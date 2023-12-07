
#ifndef _LOCATABLE_H_
#define _LOCATABLE_H_

// Locatable.h

#include "MT4_Thing.h"
#include "GPS.h"

#include "ecs36b_Common.h"
using namespace std;

class Locatable : public MT4_Thing
{
 private:
 protected:
 public:

  GPS_DD      * location;
  
  Locatable(void);

  bool operator==(const Locatable&);
  virtual Json::Value dump2JSON();
};

#endif /* _LOCATABLE_H_ */
