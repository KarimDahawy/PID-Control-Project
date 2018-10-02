#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID()
{
    /********************
     * Initialize Errors *
     *********************/
    p_error = 0;
    i_error = 0;
    d_error = 0;

    /**************************
     * Initialize Coefficients *
     ***************************/
    Kp = 0;
    Ki = 0;
    Kd = 0;
}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_)
{
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
}

void PID::UpdateError(double cte)
{
    // In this function we have the current cte 
    d_error  = cte - p_error;
    p_error  = cte;
    i_error  = i_error + cte;
}

double PID::TotalError()
{
    // Calculate the total PID error
    double PID_error = -Kp * p_error - Ki * i_error - Kd * d_error;

    return PID_error;
}

