#ifndef DEV
#define DEV
#include "utils.hpp"
#include <stdint.h>

class Device
{
public:
	Device(uint8_t pinNumber, volatile uint8_t *ddrReg, volatile uint8_t *pinReg, volatile uint8_t *portReg);

	const uint8_t pinNumber;
	volatile uint8_t *const ddrReg;
	volatile uint8_t *const pinReg;
	volatile uint8_t *const portReg;
	bool configState = false;

	bool configDevOutput();
	bool configDevInput();

	bool isPinNumber();
	bool isPinReg();
	bool isPortReg();
	bool isDdrReg();
};
#endif