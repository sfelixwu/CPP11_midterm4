
#include "MT4_Thing.h"

MT4_Thing::MT4_Thing
(void)
{
  this->sequence_num = 0;
}

bool
MT4_Thing::operator==
(const MT4_Thing& another)
{
  std::cout << "MT4_Thing::operator == was called\n";
  return (this->sequence_num == another.sequence_num);
}

Json::Value
MT4_Thing::dump2JSON
()
{
  Json::Value result;

  if (this->sequence_num != 0)
    {
      result["sequence number"] = this->sequence_num;
    }

  return result;
}
