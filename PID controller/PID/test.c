#include "PID.h"


void init_test()
{
	PID_init(0, 0.000478, 0.00478, 0, 0.02, 0);
	PID_init(1,0.0004, 0.004,0, 0.02, 0);
	PID_init(2, 0.012, 0.12, 0, 0.02, 0);
	PID_init(3, 0.012, 0.12, 0, 0.02, 0);
}

float test(int nr, float des, float meas)
{
	
	float y= PID_update(nr,des,meas);
	
	return y;

}

float test_test(float a)
{
	return 15.0;
}