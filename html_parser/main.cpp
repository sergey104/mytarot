#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

#include "/usr/local/include/gumbo.h"


#include <sstream>

#include <vector>
using namespace std;
std::vector<string> tokenize(const std::string &s)
{
    string temp = s;
    vector<string> v;
    istringstream buf(temp);
    int count = 0;
    for(string word; buf >> word; ) {
        if(word == "Previous") break;
        if(count >= 2) v.push_back(word);
        if(word == "-") count++;


    }
 //   for(auto a:v) {
//        cout << a << endl;
//    }
    return v;
}


static std::string cleantext(GumboNode* node) {
  if (node->type == GUMBO_NODE_TEXT) {
    return std::string(node->v.text.text);
  } else if (node->type == GUMBO_NODE_ELEMENT &&
             node->v.element.tag != GUMBO_TAG_SCRIPT &&
             node->v.element.tag != GUMBO_TAG_STYLE) {
    std::string contents = "";
    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
      const std::string text = cleantext((GumboNode*) children->data[i]);
      if (i != 0 && !text.empty()) {
        contents.append(" ");
      }
      contents.append(text);
    }
    return contents;
  } else {
    return "";
  }
}
int main(int argc, char** argv) {
 if (argc != 2) {
    std::cout << "Usage: test <html filename>\n";
    exit(EXIT_FAILURE);
  }
  const char* filename = argv[1];
char * bname, *basec;
basec = strdup(filename);
bname = basename(basec);
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  ofstream myfile;
  
  myfile.open ("/home/fil/ztest/" + string(bname));
  if (!in) {
    std::cout << "File " << filename << " not found!\n";
    exit(EXIT_FAILURE);
  }

  std::string contents;
  in.seekg(0, std::ios::end);
  contents.resize(in.tellg());
  in.seekg(0, std::ios::beg);
  in.read(&contents[0], contents.size());
  in.close();
  GumboOutput* output = gumbo_parse(contents.c_str());
  std::cout << cleantext(output->root) << std::endl;
  vector<string> z = tokenize(cleantext(output->root));
  for(auto a:z) {
      if(a == "Introduction:") break;
//      if(a =="Introduction:") a = "<p>" + a;
      if(a =="General:") a = "<p>" + a;
      if(a =="Work:") a = "<p>" + a;
      if(a =="Love:") a = "<p>" + a;
      if(a =="Finances:") a = "<p>" + a;
      if(a =="Health:") a = "<p>" + a;
      if(a =="Spirituality:") a = "<p>" + a;
  myfile << a << " ";
  }
  myfile.close();
gumbo_destroy_output(&kGumboDefaultOptions, output);
}
