#ifndef DIRECT_H
#define DIRECT_H

#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <list>
using namespace std;
std::list<string> read_dir (string dir)
  {
    DIR *dp;
    list<string> v;
    struct dirent *ep;
    dp = opendir (dir.c_str());
      if (dp != NULL)
      {
         while (ep = readdir (dp))
         v.push_back(string(ep->d_name));
        (void) closedir (dp);
          }
          else
    puts ("Couldn't open the directory.");
          return v;
}

#endif // DIRECT_H
