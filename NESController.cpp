/*
	NESController.cpp - NES Controller library
	Copyright (c) 2018 Kev Duc. All right reserved.
*/

#include "NESController.h"

#include "Arduino.h"

NESController::NESController(int dataPin, int clockPin, int latchPin) : _dataPin(dataPin), _clockPin(clockPin), _latchPin(latchPin) {}

void NESController::init() {
  pinInit();
  
  digitalWrite(_clockPin, HIGH); // ready to read first bit (button A)
  digitalWrite(_latchPin, HIGH); // enable button input
}

// Public Methods //////////////////////////////////////////////////////////////

void NESController::update() {
	digitalWrite(_latchPin, LOW); // disable button input
	_data = shiftIn(_dataPin, _clockPin, LSBFIRST); // read button values
	digitalWrite(_clockPin, HIGH); // reset
	digitalWrite(_latchPin, HIGH); // re-enable button input
}

boolean NESController::isPressed(int button) {
	return bitRead(_data, button) == LOW;
}

byte NESController::getRawData() {
	return _data;
}

// Private Methods /////////////////////////////////////////////////////////////

void NESController::pinInit() {
  pinMode(_dataPin, INPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
}