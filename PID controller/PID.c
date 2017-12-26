#include <stdio.h>

typdef struct  {
	float kp ; //gain  P (proportional term)
    float ki;  //gain I (integral term )
    float kd;  //gain D (derivative term)
    float dt;
    float LastError;
    float Integral;
	float error;
}PID

PIDs[]=[PID PID1, PID PID2, PID PID3, PID PID4]; 

void PID_init(nr, kp, ki, kd, dt):
{
	PIDs[nr].kp = kp;  
    PIDs[nr].ki = ki;   
    PIDs[nr].kd = kd;  
    PIDs[nr].dt = dt; 
    PIDs[nr].Integral = 0;
    PIDs[nr].LastError = 1;
	PIDs[nr].error = 0;
	return 0;
}  

float PID_update(nr, desired, measured):
{
    
	
	error = desired - measured;
    p = PIDs[nr].kp * error;
    PIDs[nr].Integral += (error + PIDs[nr].LastError) * PIDs[nr].dt * 0.5;
    d = ( (error - PIDs[nr].LastError)/PIDs[nr].dt) * PIDs[nr].kd;

    PIDs[nr].LastError = error;

    return p + PIDs[nr].Integral*PIDs[nr].ki + d; 
}
//low-pass filter - 
//define values
