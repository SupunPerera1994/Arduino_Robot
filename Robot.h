// Robot.h

#ifndef ROBOT_H
#define ROBOT_H
#include "Arduino.h"
#include "Timer.h"
#include "Propulsion.h"
#include "Oscilloscope.h"
#include "CollisionAvoidance.h"

#define POTPIN 5  //Pin where potentiometer is connected to
#define LOOPFREQ 10  //Frequency of main loop

class Robot
{
private:
	Timer timer;
	Oscilloscope oscilloscope;
	Propulsion propulsion;
	CollisionAvoidance collisionAvoidance;
	int progress;
public:
	Robot();
	void run();
	void initialize();
	Motor* getPointerToMotorL();
	Motor* getPointerToMotorR();
};

#endif

