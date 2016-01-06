#include "Arduino.h"
#include "Licht.h"

Licht::Licht(int pin)
{
	pinMode(pin, OUTPUT);
	_pin = pin;
}

void Licht::aan() {
	digitalWrite(_pin, HIGH);
}

void Licht::uit() {
	digitalWrite(_pin, LOW);
}

void Licht::dim(int l) {
	analogWrite(_pin, l);
}
