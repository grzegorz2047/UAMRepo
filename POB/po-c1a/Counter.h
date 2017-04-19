#include <iostream>

class Counter
{
  int n;

public:
  Counter();
  Counter& set(int i);
  int get();
  virtual Counter& incr();
};

