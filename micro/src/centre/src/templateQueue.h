#pragma once
#include <semaphore.h>
#include <pthread.h>
/*
require class T
copyFrom(const T &src);
checkTo(T &dst);
action(void *p);
*/

template<class T>
class templateQueue
{
public:
    templateQueue(size_t queueSize);
    ~templateQueue();
private:
	    pthread_mutex_t lock;
	    sem_t  wait;
	    T* member;
	    int size;
	    int read_pos;
	    int write_pos;
	    void memberWrite(int pos,T const &src);
	    void memberRead(int pos,T &dst);
	    void memberCheck(int pos,T &dst);
	    void memberAction(int pos,void *p);
public:
    void pushBack(T const &src);
    void popFront(T &dst);
    void check(T &dst);
    void act(void *p);
    bool isEmpty(void){
        if(read_pos == write_pos){
            return true;
        }
        else{
            return false;
        }
    }
};

template<class T>
templateQueue<T>::templateQueue(size_t queueSize){
    /* init lock and sem */
    pthread_mutex_init (&lock, NULL);
    sem_init (&wait, 0, 0);
    read_pos = 0;
    write_pos = 0;
    /* allocate message memory */
    member = new T[queueSize];
    size = queueSize;
}

template<class T>
templateQueue<T>::~templateQueue(){
    delete [] member;
}

template<class T>
void templateQueue<T>::memberWrite(int pos,T const &src){
    member[pos].copyFrom(src);
}

template<class T>
void templateQueue<T>::memberRead(int pos,T &dst){
    dst.copyFrom(member[pos]);
}

template<class T>
void templateQueue<T>::memberCheck(int pos,T &dst){
    member[pos].checkTo(dst);
}

template<class T>
void templateQueue<T>::memberAction(int pos, void* p)
{
    member[pos].action(p);
}

template<class T>
void templateQueue<T>::pushBack(T const &src){
    /* lock the message queue */
    pthread_mutex_lock (&lock);

    /* check if the queue is full. */
    if ((write_pos + 1)% size == read_pos) {
        /* Message queue is full. */
        pthread_mutex_unlock (&lock);
        return;
    }

    /* write a data to write_pos. */
    memberWrite(write_pos,src);
    write_pos ++;

    /* check if write_pos if overflow. */
    if (write_pos >= size)
        write_pos = 0;

    /* release lock */
    pthread_mutex_unlock (&lock);

    sem_post (&wait);
}

template<class T>
void templateQueue<T>::popFront(T &dst){
    sem_wait (&wait);

    /* lock the message queue */
    pthread_mutex_lock (&lock);

    /* check if queue is empty */
    if (read_pos != write_pos) {
        memberRead(read_pos,dst);

    /* read a data and check if read_pos is overflow */
        read_pos ++;
        if (read_pos >= size)
            read_pos = 0;
         pthread_mutex_unlock (&lock);
        return;
    }

    /* release lock*/
    pthread_mutex_unlock (&lock);
}

template<class T>
void templateQueue<T>::check(T &dst){
    sem_wait (&wait);

    /* lock the message queue */
    pthread_mutex_lock (&lock);

    /* check if queue is empty */
    if (read_pos != write_pos){
        memberCheck(read_pos,dst);
        /* release lock*/
        pthread_mutex_unlock (&lock);
        sem_post (&wait);
    }
    else{
        /* release lock*/
        pthread_mutex_unlock (&lock);
        sem_post (&wait);
    }
}

template<class T>
void templateQueue<T>::act(void *p){
    sem_wait (&wait);

    /* lock the message queue */
    pthread_mutex_lock (&lock);

    /* check if queue is empty */
    if (read_pos != write_pos){
        memberAction(read_pos,p);
        /* release lock*/
        pthread_mutex_unlock (&lock);
        sem_post (&wait);
    }
    else{
        /* release lock*/
        pthread_mutex_unlock (&lock);
        sem_post (&wait);
    }
}
