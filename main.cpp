#include "my_global.h"
#include "general.h"
#include <mysql/mysql.h>
#include <vector>
#include <string>
using namespace std;

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}
int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }  

  if (mysql_real_connect(con, "localhost", "root", "Remcolor_777", 
          "testdb", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, "DROP TABLE IF EXISTS Cards")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "CREATE TABLE Cards(Id INT, Name INT, Meaning TEXT)")) {      
      finish_with_error(con);
  }

  int k = 0;
  for(auto& elem:pairs) {
//cout << elem.num << "  " << elem.read << endl;

	std::string s1 = std::to_string(elem.num);
    std::string s = "INSERT INTO Cards VALUES("+std::to_string(k)+"," + s1 + "," + "\""+elem.read+"\")";
	  cout << s << endl;
  if (mysql_query(con, s.c_str())) {
      finish_with_error(con);
  }  
	  k++;
  }
  
  

  mysql_close(con);
  exit(0);
}
