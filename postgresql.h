#include <stdio.h>
 #include <postgresql/libpq-fe.h>
 #include "http_server.h"
 #include <string>
 
namespace geo {
class PostgreSql {
public:
  void connect(geo::KVMap data);

};
}


