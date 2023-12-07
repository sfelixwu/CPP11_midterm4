
// ecs36b test_MT4_q1_part1.cpp

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
  Shadow_Thing shadow_object_1002 { "http://localhost:8300", "Holdable", "1001" };
  MT4_Thing * mt4_thing_ptr = NULL;
  mt4_thing_ptr = &shadow_object_1002;

  try {
    result = Tracking_MT4_Thing(mt4_thing_ptr);
    cout << result.toStyledString() << endl;
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }

  return 0;
}
