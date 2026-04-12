#ifndef LEDD
#define LEDD

#include <stdint.h>
#include "device.hpp"

typedef enum
{
	red,
	green,
	blue,
	yellow
} LedColor;

class LED : public Device
{
public:
	LED(uint8_t pinNumber, uint8_t *ddrReg, uint8_t *portReg);
	void on();
	void off();

private:
};

#endif