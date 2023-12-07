
#ifndef _SHADOW_THING_H_
#define _SHADOW_THING_H_

#include "MT4_Thing.h"

class Shadow_Thing: public MT4_Thing
{
 private:
 public:
  
  std::string host_url;
  std::string class_name;
  std::string object_id;

  Shadow_Thing(std::string, std::string, std::string);
  virtual Json::Value dump2JSON(void); // print the content of the object
};

#endif // _SHADOW_THING_H_
