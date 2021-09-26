/*
	NESController.h - NES Controller library
	Copyright (c) 2018 Kev Duc. All right reserved.
*/

#ifndef NESCONTROLLER_H
#define NESCONTROLLER_H

#include "Arduino.h"

#define NESCTRL_A       0
#define NESCTRL_B			  1
#define NESCTRL_SELECT	2
#define NESCTRL_START	  3
#define NESCTRL_UP		  4
#define NESCTRL_DOWN		5
#define NESCTRL_LEFT		6
#define NESCTRL_RIGHT	  7

class NESController {
	public:
		NESController(int dataPin, int clockPin, int latchPin);
		void init();
		void update();
		boolean isPressed(int button);
		byte getRawData();

	private:
		int _dataPin;
		int _clockPin;
		int _latchPin;
		byte _data;
    
    void pinInit();
};

#endif // NESCONTROLLER_H

