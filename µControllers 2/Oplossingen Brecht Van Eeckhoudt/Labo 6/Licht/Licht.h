#ifndef Licht_h
#define Licht_h
#include "Arduino.h"

class Licht
{
	public:
		Licht(int pin);
		void aan();
		void uit();
		void dim(int l);
	private:
		int _pin;
};
#endif