// #include "device.hpp"
#include "button.hpp"
#include "utils.hpp"

PushButton::PushButton(
	uint8_t pinNumber, uint8_t *ddrReg, uint8_t *pinReg)
	: Device(pinNumber, ddrReg, pinReg, nullptr)
{

	configDevInput();
}

bool PushButton::getValue()
{
	// false: means is pressed

	if (configState)
	{
		// to avoid keep pressing
		// and can add some delay for bouncing

		if (GET_BIT(*pinReg, pinNumber) == false)
		{
			while (GET_BIT(*pinReg, pinNumber) == false)
				;
			return false;
		}
	}
	return true;
}
