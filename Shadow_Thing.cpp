
#include "Shadow_Thing.h"

// JSON RPC part
#include "mt4client.h"
#include "mt4server.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

Shadow_Thing::Shadow_Thing
(std::string arg_host_url, std::string arg_class_name, std::string arg_object_id)
{
  this->host_url = arg_host_url;
  this->class_name = arg_class_name;
  this->object_id = arg_object_id;
  std::cout << "Shadow_Thing Object created" << std::endl;
}

Json::Value
Shadow_Thing::dump2JSON()
{
  HttpClient httpclient((this->host_url).c_str());
  mt4Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value result;

  try {
    result = myClient.dump2JSON("dump2JSON", (this->class_name).c_str(),
				(this->object_id).c_str());
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  
  return result;
}
