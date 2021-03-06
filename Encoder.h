// Encoder.h

#ifndef ENCODER_H
#define ENCODER_H
#include "Arduino.h"

class Encoder
{
private:
	int encoderPin;
	long encoderTicks;
	long prevEncoderTicks;
	int speed;
public:
	Encoder(int encoderPin);
	void updateEncoder();
	int calcSpeed();
	int getSpeed();
	void reset();
	long getEncoderTicks();
	long getPrevEncoderTicks();
	Encoder* getPointer();
};
#endif

