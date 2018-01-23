#include <stdio.h>
#include <PID.c>


float test(int nr, float des, float meas)
{
	
	PID_init(1, 0.012, 0.12, 0, 0.2, 0)
	PID_init(2, 0.012, 0.12, 0, 0.2, 0)
	PID_init(3, 0.012, 0.12, 0, 0.2, 0)
	PID_init(4, 0.012, 0.12, 0, 0.2, 0)
	PID_update(nr,des,meas)
	
	return c;

}
	