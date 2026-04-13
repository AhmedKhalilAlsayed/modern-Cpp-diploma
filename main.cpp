#include <stdint.h>
#include "singleton_parking.cpp"
#include "factory.cpp"

void main()
{
	// client

	// auto press = SensorFactory().createPressSensor();
	// auto press = SensorFactory::createPressSensor();
	// press.get()->calibrate();

	auto temp = SensorFactory::createTempSensor();
	
	temp.get()->readvalue();

	while (true)
	{
	}
}