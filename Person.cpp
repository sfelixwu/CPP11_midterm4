
#include "Person.h"

Person::Person(std::string arg_SSN, std::string arg_name)
{
  this->SSN = arg_SSN;
  this->name = arg_name;
  this->home = NULL;
}

Person::Person(std::string arg_SSN, std::string arg_name, GPS_DD * arg_home_ptr)
{
  this->SSN = arg_SSN;
  this->name = arg_name;
  this->home = arg_home_ptr;
}

Person::Person()
{
  this->SSN = "";
  this->name = "";
  this->home = NULL;
}

void
Person::setHome
(GPS_DD * arg_home_ptr)
{
  this->home = arg_home_ptr;
}

void
Person::setLocation
(GPS_DD * arg_location_ptr, JvTime arg_time)
{
  this->location = arg_location_ptr;
  this->since_when = arg_time;
}

GPS_DD *
Person::getHome
(void)
{
  return this->home;
}

std::string
Person::getSSN()
{
  return this->SSN;
}

std::string
Person::getName()
{
  return this->name;
}

// function prototype
bool
Person::operator==
(Person& aPerson)
{
  return (this->SSN == aPerson.getSSN());
}

Json::Value
Person::dump2JSON
()
{
  Json::Value result;
  if (this->name != "")
    {
      result["name"] = this->name;
    }

  if (this->SSN != "")
    {
      result["SSN"] = this->SSN;
    }

  if (this->home != NULL)
    {
      result["home"] = (this->home)->dump2JSON();
    }

  return result;
}
