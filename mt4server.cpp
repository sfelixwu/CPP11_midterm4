
#include "ecs36b_Common.h"
#include "ecs36b_Exception.h"
#include "mt4server.h"
#include "mt4client.h"
#include <jsonrpccpp/server/connectors/httpserver.h>

// Objects
#include "Person.h"
#include "Labeled_GPS.h"
#include "Holdable.h"
Holdable *object_1001 = NULL;

using namespace jsonrpc;
using namespace std;

class mymt4Server : public mt4Server
{
public:
  mymt4Server(jsonrpc::AbstractServerConnector &conn, jsonrpc::serverVersion_t type);
  virtual Json::Value dump2JSON(const std::string& action, const std::string& class_name,
				const std::string& object_id);
};

mymt4Server::mymt4Server(AbstractServerConnector &connector, serverVersion_t type)
  : mt4Server(connector, type)
{
  std::cout << "mymt4Server Object created" << std::endl;
}

// member functions

Json::Value
mymt4Server::dump2JSON
(const std::string& action, const std::string& class_name,
 const std::string& object_id)
{
  Json::Value result;
  std::cout << action << " " << class_name << " " << object_id << std::endl;

  time_t ticks; 
  ticks = time(NULL);
  struct std::tm * my_tm_ptr = gmtime(&ticks);

  char buffer[128];
  bzero(buffer, 128);
  std::strftime(buffer, 32, "%Y-%m-%dT%H:%M:%S", my_tm_ptr);
  printf("at %s\n", buffer);

  if ((object_1001 == NULL) ||
      (class_name != "Holdable") ||
      (object_id != "1001"))
    {
      result["status"] = "Object or Class not found";
    }
  else
    {
      result = object_1001->dump2JSON();
      result["status"] = "successful";
    }
  std::cout << result.toStyledString() << std::endl;
  return result;
}

int
main
(void)
{
  Labeled_GPS gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306,
				  "Teaching and Learning Complex" };
  Person Felix { "987654321", "Felix" };

  object_1001 = new Holdable { };
  object_1001->holder = &Felix;
  object_1001->location = &gps_TLC_UCDavis;
  object_1001->sequence_num = 1001;

  HttpServer httpserver(8300);
  mymt4Server s(httpserver,
	       JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}
