#include <stdio.h>
 #include <postgresql/libpq-fe.h>
 #include <string>
 #include "postgresql.h"
 
 void geo::PostgreSql::connect(geo::KVMap data) {
 
 PGconn          *conn;
 PGresult        *res;
 int             rec_count;
 int             row;
int             col;



         conn = PQconnectdb("dbname=postgres host=localhost user=postgres password=root");

        if (PQstatus(conn) == CONNECTION_BAD) {
                 puts("We were unable to connect to the database");
                 
         }
 std::string id;
 std::string password;
      for (auto &it : data) {
    if(it.first == "username") { id=it.second;}
    if(it.first == "password") { password=it.second;}
  }
  
   //printf("%s\t", ("select * from public.empdetails where empid='"+id+"'").c_str());
         res = PQexec(conn,
                 ("select * from public.empdetails where empid='"+id+"'").c_str());
 
         if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                 puts("We did not get any data!");
                
         }
 
         rec_count = PQntuples(res);
 
         printf("We received %d records.\n", rec_count);
         puts("==========================");
 
         for (row=0; row<rec_count; row++) {
                 for (col=0; col<11; col++) {
                         printf("%s\t", PQgetvalue(res, row, col));
                 }
                 puts("");
         }
 
         puts("==========================");
 
         PQclear(res);
 
        PQfinish(conn);
}
