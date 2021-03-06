#include <string>
#include <string.h>
#include "json/json.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
class loaddata
{
	public:
	    void load_cfgdata(string &input, string& output);	
};

void loaddata::load_cfgdata(string &input, string& output)
{
	Json::Reader reader;
  	Json::Value root;

  	std::string path = getenv("HOME");
  	path+="/centreCfg/guide.json";
	ifstream myfile(path.c_str(), ios::binary);
	if( !myfile.is_open() )  
	{ 
	    cout << "Error opening file\n"; 
	}

    std::string filestr,tmp;
    while (!myfile.eof() )
    {
        myfile >> tmp;
        filestr += tmp;
	}

  	if (reader.parse(filestr, root))
	{
    	const Json::Value arrayObj = root["guidePoint"];
        
    	for (size_t i=0; i<arrayObj.size(); i++) 
		{
     	    int id = arrayObj[i]["id"].asInt();
      	    string keyword = arrayObj[i]["voiceKey"].asString();
            string command = arrayObj[i]["voiceCommand"].asString();
            const char* str = strstr(input.c_str(),keyword.c_str());
            if (str!=NULL)
            {
                //std::cout << id << " is " << keyword << command << std::endl;
                output = command;
            } 

        }
  	}

	else 
	{
    	cout << "parse error" << endl;
  	}

    myfile.close();
}
