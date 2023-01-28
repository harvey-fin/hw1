#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;


//Use this file to test your ulliststr implementation before running the test suite


int main(int argc, char* argv[])
{
  // ULListStr dat;
  // dat.push_back("7");
  // dat.push_front("8");
  // dat.push_back("9");
  // cout << dat.get(0) << "* " << dat.get(1) << " " << dat.get(2) << endl;
  // // prints: 8 7 9
  // cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
  // cout << dat.front() << endl;

  // ULListStr test;
  // test.push_back("76810923487019274");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");
  // test.push_back("10241308471047109");

  // cout << test.back() << endl;
  // cout << test.get(0) << " " << test.get(1) << " " << test.get(2) << endl;
  ULListStr list;

	list.push_back("a");

	list.pop_front();
  cout << list.size() <<endl;


}



