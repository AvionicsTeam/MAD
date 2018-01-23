#include <stdio.h>


typedef struct {
	float kp;
	float ki;
	float kd;
	float dt;
	float LastError;
	float Integral;
	float windup;
}PID;

PID PIDs[4];

void PID_init(int nr, float kp, float ki, float kd, float dt, float windup)
{
	PIDs[nr].kp = kp;
	PIDs[nr].ki = ki;
	PIDs[nr].kd = kd;
	PIDs[nr].dt = dt* 0.5;
	PIDs[nr].Integral = 0;
	PIDs[nr].LastError = 1;
	PIDs[nr].windup = windup;

}

float PID_update(int nr, float desired, float measured)
{
	
	float error = desired - measured;
	float p = PIDs[nr].kp * error;
	PIDs[nr].Integral += (error + PIDs[nr].LastError) * PIDs[nr].dt ;
	//ANTIWINDUP
	if(PIDs[nr].windup != 0)
	{
		if(PIDs[nr].Integral>PIDs[nr].windup)
			PIDs[nr].Integral = PIDs[nr].windup;
		if(PIDs[nr].Integral<-PIDs[nr].windup)
			PIDs[nr].Integral = -PIDs[nr].windup;
	}
	float d = ( (error - PIDs[nr].LastError)/PIDs[nr].dt) * PIDs[nr].kd;

	PIDs[nr].LastError = error;

	return p + PIDs[nr].Integral*PIDs[nr].ki + d;
}
