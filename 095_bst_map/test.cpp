#include <string.h>

#include <iostream>

#include "bstmap.h"
using namespace std;

int main() {
  BstMap<int, int> * ptr = new BstMap<int, int>;
  ptr->add(4, 4);
  ptr->add(3, 2);
  ptr->add(-1, 4);
  ptr->add(0, 0);
  ptr->printTesting();

  delete ptr;
  return 0;
}
