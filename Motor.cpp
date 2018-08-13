// 
// 
// 

#include "Motor.h"

Motor::Motor(int directionPin, int enablePin, int encoderPin, float Kp, float Kd)
	: directionPin(directionPin), enablePin(enablePin), PWM_val(0), mDirection(true), encoder(encoderPin), pid(Kp, Kd)
{
	pinMode(this->directionPin, OUTPUT);
	pinMode(this->enablePin, OUTPUT);
	analogWrite(this->enablePin, PWM_val);
	setDirection(mDirection);
}

void Motor::setDirection(bool direction)
{
	mDirection = direction;
	digitalWrite(directionPin, mDirection);
}

void Motor::setSpeed(int speed)
{
	this->speed = speed;
}

void Motor::handleEncoder()
{
	encoder.updateEncoder(mDirection);
}

Motor* Motor::getPointer()
{
	return this;
}

void Motor::setPWM_val(int PWM_val)
{
	this->PWM_val = constrain(PWM_val,0,255);
	analogWrite(enablePin, this->PWM_val);
}

void Motor::driveConstantSpeed(int speed)
{
	this->speed = speed;
	setPWM_val(pid.calcPidTerm(speed, encoder.calcSpeed()));
}

int Motor::calcPWM_val()
{
	return pid.calcPidTerm(speed, encoder.calcSpeed());
}

int Motor::getSpeed()
{
	return speed;
}

Encoder* Motor::getPointerToEncoder()
{
	return encoder.getPointer();
}

int Motor::getPWM_val()
{
	return PWM_val;
}