void PID_init(int nr, float kp, float ki, float kd, float dt, float windup);

float PID_update(int nr, float desired, float measured);