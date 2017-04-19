#include "BadCounter.h"
#include <iostream>
BadCounter& BadCounter::incr()
{
	//std::cout << badIncr;
	if(badIncr == 2){
		badIncr = 0;	
	}else{
		Counter::incr();
		badIncr++;
	}
	return *this;
}
