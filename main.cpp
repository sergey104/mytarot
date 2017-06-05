#include "my_global.h"
#include "general.h"
#include "pp.h"
#include <mysql/mysql.h>
#include <vector>
#include <string>
#include <fstream>
#include "direct.h"
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
 // General
  if (mysql_query(con, "DROP TABLE IF EXISTS General")) {
      finish_with_error(con);
  }
  
  if (mysql_query(con, "CREATE TABLE General(Id INT, Card_Id INT, Meaning TEXT)")) {
      finish_with_error(con);
  }

  int k = 0;
  for(auto& elem:pairs_gen) {
//cout << elem.num << "  " << elem.read << endl;

	std::string s1 = std::to_string(elem.num);
    std::string s = "INSERT INTO General VALUES("+std::to_string(k)+"," + s1 + "," + "\""+elem.read+"\")";
	  cout << s << endl;
  if (mysql_query(con, s.c_str())) {
      finish_with_error(con);
  }  
	  k++;
  }
 /////////////////////  Past
  if (mysql_query(con, "DROP TABLE IF EXISTS Past")) {
      finish_with_error(con);
  }

  if (mysql_query(con, "CREATE TABLE Past(Id INT, Name INT, Meaning TEXT)")) {
      finish_with_error(con);
  }

  int kk = 0;
  for(auto& elem:pairs_past) {
//cout << elem.num << "  " << elem.read << endl;

        std::string s11 = std::to_string(elem.num);
    std::string ss = "INSERT INTO Past VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
          cout << ss << endl;
  if (mysql_query(con, ss.c_str())) {
      finish_with_error(con);
  }
          kk++;
  }

  /////////////////////  Present
   if (mysql_query(con, "DROP TABLE IF EXISTS Present")) {
       finish_with_error(con);
   }

   if (mysql_query(con, "CREATE TABLE Present(Id INT, Name INT, Meaning TEXT)")) {
       finish_with_error(con);
   }

   kk = 0;
   for(auto& elem:pairs_present) {
 //cout << elem.num << "  " << elem.read << endl;

         std::string s11 = std::to_string(elem.num);
     std::string ss = "INSERT INTO Present VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
           cout << ss << endl;
   if (mysql_query(con, ss.c_str())) {
       finish_with_error(con);
   }
           kk++;
   }

   /////////////////////  Future
    if (mysql_query(con, "DROP TABLE IF EXISTS Future")) {
        finish_with_error(con);
    }

    if (mysql_query(con, "CREATE TABLE Future(Id INT, Name INT, Meaning TEXT)")) {
        finish_with_error(con);
    }

    kk = 0;
    for(auto& elem:pairs_future) {
  //cout << elem.num << "  " << elem.read << endl;

          std::string s11 = std::to_string(elem.num);
      std::string ss = "INSERT INTO Future VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
            cout << ss << endl;
    if (mysql_query(con, ss.c_str())) {
        finish_with_error(con);
    }
            kk++;
    }

    /////////////////////  Yes/No
     if (mysql_query(con, "DROP TABLE IF EXISTS YesNo")) {
         finish_with_error(con);
     }

     if (mysql_query(con, "CREATE TABLE YesNo(Id INT, Name INT, Meaning TEXT)")) {
         finish_with_error(con);
     }

     kk = 0;
     for(auto& elem:pairs_yesno) {
   //cout << elem.num << "  " << elem.read << endl;

           std::string s11 = std::to_string(elem.num);
       std::string ss = "INSERT INTO YesNo VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
             cout << ss << endl;
     if (mysql_query(con, ss.c_str())) {
         finish_with_error(con);
     }
             kk++;
     }

     ////////////////////  Sarray
          if (mysql_query(con, "DROP TABLE IF EXISTS Sarray")) {
              finish_with_error(con);
          }

          if (mysql_query(con, "CREATE TABLE Sarray(Id INT, Name INT, Meaning TEXT)")) {
              finish_with_error(con);
          }

          kk = 0;
          for(auto& elem:pairs_sarray) {
        //cout << elem.num << "  " << elem.read << endl;

                std::string s11 = std::to_string(elem.num);
            std::string ss = "INSERT INTO Sarray VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
                  cout << ss << endl;
          if (mysql_query(con, ss.c_str())) {
              finish_with_error(con);
          }
                  kk++;
          }

   /////////////////////  Addd
     if (mysql_query(con, "DROP TABLE IF EXISTS Addd")) {
               finish_with_error(con);
     }

     if (mysql_query(con, "CREATE TABLE Addd(Id INT, Name INT, Meaning TEXT)")) {
         finish_with_error(con);
     }

     kk = 0;
     for(auto& elem:pairs_addd) {
     //cout << elem.num << "  " << elem.read << endl;

       std::string s11 = std::to_string(elem.num);
       std::string ss = "INSERT INTO Addd VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
            cout << ss << endl;
     if (mysql_query(con, ss.c_str())) {
        finish_with_error(con);
      }
             kk++;
     }

     /////////////////////  Day
       if (mysql_query(con, "DROP TABLE IF EXISTS Day")) {
                 finish_with_error(con);
       }

       if (mysql_query(con, "CREATE TABLE Day(Id INT, Name INT, Meaning TEXT)")) {
           finish_with_error(con);
       }

       kk = 0;
       for(auto& elem:pairs_day) {
       //cout << elem.num << "  " << elem.read << endl;

         std::string s11 = std::to_string(elem.num);
         std::string ss = "INSERT INTO Day VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
              cout << ss << endl;
       if (mysql_query(con, ss.c_str())) {
          finish_with_error(con);
        }
               kk++;
       }


       /////////////////////  Ppast
         if (mysql_query(con, "DROP TABLE IF EXISTS Ppast")) {
                   finish_with_error(con);
         }

         if (mysql_query(con, "CREATE TABLE Ppast(Id INT, Name INT, Meaning TEXT)")) {
             finish_with_error(con);
         }

         kk = 0;
         for(auto& elem:pairs_Ppast) {
         //cout << elem.num << "  " << elem.read << endl;

           std::string s11 = std::to_string(elem.num);
           std::string ss = "INSERT INTO Ppast VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
                cout << ss << endl;
         if (mysql_query(con, ss.c_str())) {
            finish_with_error(con);
          }
                 kk++;
         }
         /////////////////////  Ppresent
           if (mysql_query(con, "DROP TABLE IF EXISTS Ppresent")) {
                     finish_with_error(con);
           }

           if (mysql_query(con, "CREATE TABLE Ppresent(Id INT, Name INT, Meaning TEXT)")) {
               finish_with_error(con);
           }

           kk = 0;
           for(auto& elem:pairs_Ppresent) {
           //cout << elem.num << "  " << elem.read << endl;

             std::string s11 = std::to_string(elem.num);
             std::string ss = "INSERT INTO Ppresent VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
                  cout << ss << endl;
           if (mysql_query(con, ss.c_str())) {
              finish_with_error(con);
            }
                   kk++;
           }

           /////////////////////  Pfuture
             if (mysql_query(con, "DROP TABLE IF EXISTS Pfuture")) {
                       finish_with_error(con);
             }

             if (mysql_query(con, "CREATE TABLE Pfuture(Id INT, Name INT, Meaning TEXT)")) {
                 finish_with_error(con);
             }

             kk = 0;
             for(auto& elem:pairs_Pfuture) {
             //cout << elem.num << "  " << elem.read << endl;

               std::string s11 = std::to_string(elem.num);
               std::string ss = "INSERT INTO Pfuture VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+elem.read+"\")";
                    cout << ss << endl;
             if (mysql_query(con, ss.c_str())) {
                finish_with_error(con);
              }
                     kk++;
             }

vector<reading> rr;
int ii=0;
ifstream in;    // Create an input file stream.
 string str;
list<string> z = read_dir("/home/fil/ztest");
z.sort();
for(auto& el:z) {
cout << el <<  endl;
    if(el == ".") continue;
    if(el == "..") continue;
  in.open("/home/fil/ztest/" + el);  // Use it to read from a file named data.txt.
   getline(in,str);  // Get the frist line from the file, if any.
   reading r(ii,str) ;
 rr.push_back(r);
 ii++;
 in.close();
}
/////////////////////  Info
  if (mysql_query(con, "DROP TABLE IF EXISTS Cards")) {
            finish_with_error(con);
  }

  if (mysql_query(con, "CREATE TABLE Cards(Id INT, Name INT, Meaning TEXT)")) {
      finish_with_error(con);
  }
  for(auto& elem:rr) {
  cout << elem.num << "  " << elem.read << endl;
  }
 kk = 0;
  for(auto& elem:rr) {
  //cout << elem.num << "  " << elem.read << endl;
      int b = elem.read.length();
      char end[18000];
      mysql_real_escape_string(con,end,elem.read.c_str(),b);
    std::string s11 = std::to_string(elem.num);
    std::string ss = "INSERT INTO Cards VALUES("+std::to_string(kk)+"," + s11 + "," + "\""+string(end)+"\")";
         cout << ss << endl;
  if (mysql_query(con, ss.c_str())) {
     finish_with_error(con);
   }
          kk++;
  }
  mysql_close(con);
  exit(0);
}
