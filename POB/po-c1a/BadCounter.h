#include "Counter.h"
class BadCounter : public Counter 
{
private:
	int badIncr = 0;
public:
	BadCounter& incr();
};
