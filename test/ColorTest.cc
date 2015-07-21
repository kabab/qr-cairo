#include <iostream>
#include "../src/Color.h"

using namespace std;

int main() {

  char color[] = "#nf0011";
  
  
  //Color c1(10, 23, 45);
  //Color c1(0.25, 0.45, 0.1, 0.255);
  Color c1(color);
  
  cout << c1.red() << " " << c1.green() << " " << c1.blue()
       << endl;
  return 0;
  
}
