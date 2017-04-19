#include "Counter.h"

Counter::Counter()
{
  n=0;
}

Counter& Counter::set(int i)
{
  n=i;
  return *this;
}

int Counter::get()
{
  return n;
}

Counter& Counter::incr()
{
  ++n;
  return *this;
}
