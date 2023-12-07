
#ifndef _HOLDABLE_H_
#define _HOLDABLE_H_

// Holdable.h

#include "Locatable.h"
#include "Person.h"

#include "ecs36b_Common.h"
using namespace std;

class Holdable : public Locatable
{
 private:
 protected:
 public:

  Person     * holder;
  
  Holdable(void);

  bool operator==(const Holdable&);
  virtual Json::Value dump2JSON();
};

#endif /* _HOLDABLE_H_ */
