# **PID Controller**

## Overview
-------------------

In this Project, the main aim is to build a PID controller to control the steering and the speed of a moving vehicle using Udacity Simulator.

We will tune the PID coefficients manually in order to keep the vehicle on the track.

## PID Controller Project Goals
-------------------------------------------------------------

**The goals / steps of this project are the following:**

	1. Design a PID controller.
	2. Use the designed PID to control the steering.
	3. Tune the PID coefficients to have the perfect steering values.
	4. Use Udacity Simulator to test the PID controller.

[//]: # (Image References)

[image1]: ./PID_Design.png

## Dependencies
-------------------------------------------------------------

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Rubric points:
-------------------------------------------------------------
### 1. Compilation
-----------------------------

The code compiled successfully using cmake and make.

### 2. Implementation:
-----------------------------

The algorithm follow what's presented in the lessons. I have implemented the PID controller then tuned its parameter in order keep the vehicle inside the track.


### 3. Reflection:
------------------------------

#### PID Description

PID controller is the most common control algorithm used in industry. It stands for Proportional-Integral-Derivative Controllers. These three controllers are combined in such a way that it produces a control signal. Following are the description of these coefficients:

![alt text][image1]

##### 1. Proportional Controller

Proportional controller gives output which is proportional to CTE.
It compares desired or set point with actual value or feedback process value. The resulting error is multiplied with proportional constant **KP** to get the output.
Mainly It is responsible for having an opposite effect of the CTE. This means that if the CTE is positive, the Proportional controller should have a negative steering command.

##### 2. Integral Controller

As the proportional Controller always generate an offset, the integral controller is necessary to eliminate this offset. It takes CTE over the past time into its consideration.

##### 3. Derivative Controller

The Derivative Controller depends on the rate of the change of CTE. It reduces the overshooting caused by the proportional controller.

#### Tuning PID Coefficients