#include <stdint.h>
#include "led.hpp"
#include "button.hpp"
#include "parking.hpp"

// dummy code for
// AVR atmega32, 8-bit MCU

void main()
{
	// LED red{0, 0, 0};
	// LED blue{1, 0, 0};
	// LED green{2, 0, 0};
	// LED yellow{3, 0, 0};

	// PushButton btn{4, 0, 0};

	auto ptr = ParkingPointerSinglton::getInstance();
	auto obj = ParkingObjectSingleton::getInstance();
	auto meyer = ParkingMeyerSingleton::getInstance();
	// ptr->getCounter();

	while (true)
	{
	}
}