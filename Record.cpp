
#include "Record.h"

Record::Record()
{
}

void
Record::addWho
(Person *_p)
{
  (this->who).push_back(_p);
}

void
Record::addWhat
(MT4_Thing *_t)
{
  (this->what).push_back(_t);
}

void
Record::setWho(std::vector<Person *> _vp)
{
  this->who = _vp;
}

void
Record::setWhat(std::vector<MT4_Thing *> _vt)
{
  this->what = _vt;
}

void
Record::setWhere(GPS_DD *_g)
{
  this->where = _g;
}

void
Record::setWhen(JvTime _jt)
{
  this->when = _jt;
}

Json::Value
Record::dump2JSON()
{
  Json::Value result;

  result["label"] = this->label;
  result["where"] = (this->where)->dump2JSON();
  result["when"] = (this->when).dump2JSON();

  int i;
  for (i = 0; i < (this->who).size(); i++)
    {
      result["who"][i] = ((this->who)[i])->dump2JSON();
    }
  
  for (i = 0; i < (this->what).size(); i++)
    {
      result["what"][i] = ((this->what)[i])->dump2JSON();
    }

  return result;
}
