#include <iostream>
#include <memory>

// Target interface (what our system expects)
class TemperatureSensor
{
public:
	virtual double getTemperatureCelsius() = 0;
	virtual ~TemperatureSensor() = default;
};

// Our system's data logger
class DataLogger
{
	std::unique_ptr<TemperatureSensor> sensor;

public:
	DataLogger(std::unique_ptr<TemperatureSensor> s) : sensor(std::move(s)) {}

	void logTemperature()
	{
		double temp = sensor->getTemperatureCelsius();
		std::cout << "Temperature: " << temp << "°C" << std::endl;
	}
};

// LEGACY SENSOR 1: returns Kelvin
class OldSensorA
{
public:
	double readKelvin() { return 298.15; } // 25°C in Kelvin
};

// LEGACY SENSOR 2: returns Fahrenheit
class OldSensorB
{
public:
	double readFahrenheit() { return 77.0; } // 25°C in Fahrenheit
};

// Adapter for Sensor A (Kelvin → Celsius)
class SensorAAdapter : public TemperatureSensor
{
	OldSensorA &sensor;

public:
	SensorAAdapter(OldSensorA &s) : sensor(s) {}

	double getTemperatureCelsius() override
	{
		double kelvin = sensor.readKelvin();
		return kelvin - 273.15; // K → °C
	}
};

// Adapter for Sensor B (Fahrenheit → Celsius)
class SensorBAdapter : public TemperatureSensor
{
	OldSensorB &sensor;

public:
	SensorBAdapter(OldSensorB &s) : sensor(s) {}

	double getTemperatureCelsius() override
	{
		double fahrenheit = sensor.readFahrenheit();
		return (fahrenheit - 32) * 5.0 / 9.0; // °F → °C
	}
};

int main()
{
	OldSensorA kelvinSensor;
	OldSensorB fahrenheitSensor;

	// Adapters make legacy sensors work with our system
	auto adaptedA = std::make_unique<SensorAAdapter>(kelvinSensor);
	auto adaptedB = std::make_unique<SensorBAdapter>(fahrenheitSensor);

	DataLogger logger1(std::move(adaptedA));
	// DataLogger logger2(std::move(adaptedB));

	// logger1.logTemperature(); // Temperature: 25°C
	// logger2.logTemperature(); // Temperature: 25°C

	return 0;
}