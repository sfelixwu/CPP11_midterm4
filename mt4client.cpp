
// mt4client.cpp for Q3 for MT4

#include "Record.h"
#include "Labeled_GPS.h"
#include "Holdable.h"
#include "Shadow_Thing.h"

#include "mt4client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

Json::Value
Tracking_MT4_Thing
(MT4_Thing *arg_mt4_ptr)
{
  Json::Value result;

  if (arg_mt4_ptr == NULL)
    {
      result["status"] = "failed";
      result["error"]  = "invalid mt4 object pointer";
    }
  else
    {
      try {
	result = arg_mt4_ptr->dump2JSON();
      } catch (JsonRpcException &e) {
	cerr << e.what() << endl;
      }
    }
  return result;
}

int
main(void)
{
  Json::Value result;
  Shadow_Thing shadow_object_1001 { "http://localhost:8300", "Holdable", "1001" };

  Labeled_GPS gps_Home_Woodland { 38.672215864622636, -121.72280111121437, "Costco, Woodland" };
  Labeled_GPS gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501, "IKEA, West Sacramento" };
  Labeled_GPS gps_Target_Davis  { 38.55430358599457, -121.69974953598044, "Target, Davis" };
  Person John { "987654322", "John", &gps_Home_Woodland };

  Holdable object_1002 {};
  object_1002.holder = &John;
  object_1002.location = &gps_IKEA_Sacramento;
  object_1002.sequence_num = 1002;

  Record r1;
  r1.label = "Possession";
  r1.addWho(&John);
  r1.addWhat(&object_1002);
  r1.addWhat(&shadow_object_1001);
  JvTime r1_jv { "2023-11-17T16:00:00+0000" };
  r1.when = r1_jv;
  r1.where = &gps_Target_Davis;

  std::cout << r1.dump2JSON() << std::endl;
  return 0;
}
