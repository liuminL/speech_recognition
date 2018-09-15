// Auto-generated. Do not edit!

// (in-package centre.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class event {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.eventID = null;
      this.data = null;
    }
    else {
      if (initObj.hasOwnProperty('eventID')) {
        this.eventID = initObj.eventID
      }
      else {
        this.eventID = 0;
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type event
    // Serialize message field [eventID]
    bufferOffset = _serializer.uint32(obj.eventID, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _arraySerializer.uint8(obj.data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type event
    let len;
    let data = new event(null);
    // Deserialize message field [eventID]
    data.eventID = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.data.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'centre/event';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '306c620ab5bfeb5b7505399af72d2b3e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 eventID
    uint8[] data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new event(null);
    if (msg.eventID !== undefined) {
      resolved.eventID = msg.eventID;
    }
    else {
      resolved.eventID = 0
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = []
    }

    return resolved;
    }
};

module.exports = event;
