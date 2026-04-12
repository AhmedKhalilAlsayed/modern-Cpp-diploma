#include <stdint.h>
#include "device.hpp"

Device::Device(uint8_t pinNumber, volatile uint8_t *ddrReg, volatile uint8_t *pinReg, volatile uint8_t *portReg)
	: pinNumber(pinNumber),
	  pinReg(pinReg),
	  ddrReg(ddrReg),
	  portReg(portReg)
{
}

bool Device::configDevOutput()
{
	if (isPinNumber() && isDdrReg() && isPortReg())
	{
		SET_BIT(*ddrReg, pinNumber);
		configState = true;
	}
	return configState;
}
bool Device::configDevInput()
{
	if (isPinNumber() && isDdrReg() && isPinReg())
	{
		CLEAR_BIT(*ddrReg, pinNumber);
		configState = true;
	}
	return configState;
}

bool Device::isPinNumber()
{
	return (pinNumber < 8) ? true : false;
}
bool Device::isPinReg()
{
	// dummy function
	// but should there is a switch with predefind addr
	return true;
}
bool Device::isPortReg()
{
	// dummy function
	// but should there is a switch with predefind addr
	return true;
}
bool Device::isDdrReg()
{
	// dummy function
	// but should there is a switch with predefind addr
	return true;
}