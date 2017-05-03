#include "my_global.h"
#include <mysql/mysql.h>
#include <vector>
#include <string>
using namespace std;
struct reading {
    int num;
    string read;
  reading(int n, string r): num(n),read(r){}
  void outp() {

  cout << num << " : " << read << endl;
  }
};
std::vector< reading> pairs {{0,"qqw"},{1,"223" }};
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
	std::string s1 = std::to_string(pairs[1].num);
  std::string s = "INSERT INTO Cards VALUES(1," + s1 + "," + pairs[1].read+")";
  if (mysql_query(con, s.c_str())) {
      finish_with_error(con);
  }
  
  
  
  

  mysql_close(con);
  exit(0);
}
