
// test_MT4.cpp

#include "Holdable.h"
#include "Labeled_GPS.h"

int
main
(int argc, char *argv[])
{
  Labeled_GPS gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306,
				  "Teaching and Learning Complex" };
  Person Felix { "987654321", "Felix" };

  Holdable item_1;
  item_1.holder = &Felix;
  item_1.location = &gps_TLC_UCDavis;
  item_1.sequence_num = 1;

  MT4_Thing * mt4_ptr = &item_1;
  
  Json::Value x;
  x = mt4_ptr->dump2JSON();
  std::cout << x.toStyledString() << std::endl;

  return 0;
}
