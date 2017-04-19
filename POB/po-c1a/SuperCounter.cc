#include "SuperCounter.h"
SuperCounter& SuperCounter::step(int k)
{
	for(int i = 0; i < k; i ++)
	{
		this->Counter::incr();
	}
}
