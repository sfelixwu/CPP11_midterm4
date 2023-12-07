
#ifndef _MT4_THING_H_
#define _MT4_THING_H_

// MT4_Thing.h

#include "ecs36b_Common.h"
#include "ecs36b_Exception.h"

using namespace std;

class MT4_Thing
{
 private:
 protected:
 public:
  
  unsigned int sequence_num;

  MT4_Thing(void);
  bool operator==(const MT4_Thing&); 
  virtual Json::Value dump2JSON();
};

#endif /* _MT4_THING_H_ */
