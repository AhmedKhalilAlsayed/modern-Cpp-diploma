#ifndef BTN
#define BTN

#include <device.hpp>
#include <stdint.h>

class PushButton : public Device
{
public:
	PushButton(uint8_t pinNumber, uint8_t* ddrReg, uint8_t* pinReg);
	bool getValue();

	
};

#endif