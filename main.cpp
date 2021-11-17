#include <iostream>
#include <getopt.h>
#include <vector>
#include <algorithm>

using namespace std;


int main (int argc, char *argv[]){
  const char* shortOptions = "hvcl:";

  const struct option longOptions[] = {
    {"help", no_argument, NULL, 'h'},
    {"option", no_argument, NULL, 'o'},
    {"version", no_argument, NULL, 'v'},
    {"chars", no_argument, NULL, 'c'},
    {"line", required_argument, NULL, 'l'},
    {NULL,0,NULL,0}
  };

  int option;
  int optnIndex;

  vector<int> resOfParsingArgs;

  while ((option=getopt_long(argc, argv, shortOptions, longOptions, &optnIndex))!=-1){

    if (binary_search(resOfParsingArgs.begin(), resOfParsingArgs.end(), option)){
      continue;
    }
    else {
      resOfParsingArgs.push_back(option);
    }

    switch (option)
    {
      case 'h':
        cout << "Arg: Help\n";
        break;
      case 'v':
        cout << "Arg: Version\n";
        break;
      case 'o':
        cout << "Arg: Option\n";
        break;
      case 'c':
        cout << "Arg: Chars\n";
        break;
      case 'l':
        cout << "Arg: Line: " << optarg << endl;
        break;
      
      default:
        break;
    }
  }

    return 0;
}
