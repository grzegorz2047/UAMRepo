#include "Counter.h"
class SuperCounter : public Counter
{
public:
	SuperCounter& step(int k);
};
