#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>

#include "function.h"

extern int binarySearchForZero(Function<int, int> * f, int low, int high);

class FunctionChecker : public Function<int, int>
{
  class TooManyInvokations : std::exception
  {};
  int remaining;
  const char * name;

 public:
  virtual int reallyInvoke(int) = 0;
  FunctionChecker(const char * name) : name(name) {}
  virtual int invoke(int x) {
    if (!(remaining > 0)) {
      throw TooManyInvokations();
    }
    remaining--;
    return reallyInvoke(x);
  }
  void run(int low, int high, int expected_ans, int maxInvokations) {
    bool too_many = false;
    int ret;

    remaining = maxInvokations;
    try {
      ret = binarySearchForZero(this, low, high);
    }
    catch (const TooManyInvokations & e) {
      too_many = true;
    }
    if (too_many) {
      std::cerr << name << " invoked more than " << maxInvokations << " times.\n";
      std::exit(1);
    }
    if (ret != expected_ans) {
      std::cerr << "wrong answer when doing bsearch for " << name << ", expected = " << expected_ans
                << ", got " << ret << "\n";
      std::exit(1);
    }
  }
};

class SinCheck : public FunctionChecker
{
 public:
  SinCheck() : FunctionChecker("SinFunction") {}
  virtual int reallyInvoke(int x) { return 10000000 * (std::sin(x / 100000.0) - 0.5); }
};

class LinearCheck : public FunctionChecker
{
 public:
  LinearCheck() : FunctionChecker("LinearFunction") {}
  virtual int reallyInvoke(int x) { return x; }
};

int main() {
  SinCheck().run(0, 150000, 52359, 20);
  LinearCheck().run(1, 1, 1, 1);
  LinearCheck().run(0, 2, 0, 2);
  LinearCheck().run(1, 2, 1, 1);
  LinearCheck().run(-2, 0, -1, 2);
  LinearCheck().run(-1, 3, 0, 2);
}
