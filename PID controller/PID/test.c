#include "PID.h"


void init_test()
{
	PID_init(0, 4.7307, 10.0766, 0.5274, 0.02, 0);
	PID_init(1,0.4532, 1.8438,0.02785, 0.02, 0);
	PID_init(2, 0.012, 0.12, 0, 0.02, 0);
	PID_init(3, 0.012, 0.12, 0, 0.02, 0);
}

float test(int nr, float des, float meas)
{
	
	float y= PID_update(nr,des,meas);
	
	return y;

}
