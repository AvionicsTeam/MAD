#include "PID.h"


void init_test()
{
	PID_init(0, 0.000478, 0.0478, 0, 0.02, 0);
	PID_init(1, 0.00057, 0.057,0, 0.02, 0);
	PID_init(2, 0.012, 0.12, 0, 0.02, 0);
	PID_init(3, 0.012, 0.12, 0, 0.02, 0);
}

float test(int nr, float des, float meas)
{
	
	float y= PID_update(nr,des,meas);
	
	return y;

}
