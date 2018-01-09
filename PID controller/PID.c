#include <stdio.h>

typdef struct  {
	float kp ;
	float ki;
	float kd;
	float dt;
	float LastError;
	float Integral;
	float windup;
}PID

PIDs[]=[PID PID1, PID PID2, PID PID3, PID PID4];

void PID_init(int nr, float kp, float ki, float kd, float dt, float windup)
{
	PIDs[nr].kp = kp;
	PIDs[nr].ki = ki;
	PIDs[nr].kd = kd;
	PIDs[nr].dt = dt* 0.5;
	PIDs[nr].Integral = 0;
	PIDs[nr].LastError = 1;
	PIDs[nr].windup = windup;


	return 0;
}

float PID_update(nr, desired, measured)
{
	
	error = desired - measured;
	p = PIDs[nr].kp * error;
	PIDs[nr].Integral += (error + PIDs[nr].LastError) * PIDs[nr].dt ;
	//ANTIWINDUP
	if(PIDs[nr].windup != 0)
	{
		if(PIDs[nr].Integral>PIDs[nr].windup)
			PIDs[nr].Integral = PIDs[nr].windup;
		if(PIDs[nr].Integral<-PIDs[nr].windup)
			PIDs[nr].Integral = -PIDs[nr].windup;
	}
	d = ( (error - PIDs[nr].LastError)/PIDs[nr].dt) * PIDs[nr].kd;

	PIDs[nr].LastError = error;

	return p + PIDs[nr].Integral*PIDs[nr].ki + d;
}
