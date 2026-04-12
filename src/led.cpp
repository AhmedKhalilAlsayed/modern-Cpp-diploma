#include "utils.hpp"
#include "led.hpp"

LED::LED(uint8_t pinNumber, uint8_t *ddrReg, uint8_t *portReg)
	: Device(pinNumber, ddrReg, nullptr, portReg)
{
	configDevOutput();
}

void LED::on()
{
	SET_BIT(*portReg, pinNumber);
}
void LED::off()
{
	CLEAR_BIT(*portReg, pinNumber);
}