
#include "Holdable.h"

Holdable::Holdable
(void)
{
  this->holder = (Person *) NULL;
}

bool
Holdable::operator==
(const Holdable& another)
{
  std::cout << "Holdable::operator == was called\n";
  return ((*(this->holder) == *(another.holder)) &&
	  (((Locatable&) (*this)) == ((Locatable&) another)));
}

Json::Value
Holdable::dump2JSON
()
{
  Json::Value result = this->Locatable::dump2JSON();

  if (this->holder != NULL) 
    result["holder"] = (this->holder)->dump2JSON();
  
  return result;
}
