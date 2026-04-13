#include <iostream>
#include <memory>

// to start, should know that we have multiple sensors
// so, will make an interface/abstract for the common functions

// 1. interface
class ISensor
{
public:
	virtual ~ISensor() = default;

	virtual float readvalue() = 0;
	virtual void calibrate() = 0;
};

// 2. concrete class (sensors)
class TempSensor : public ISensor
{
public:
	TempSensor() {}
	~TempSensor() override = default;

	float readvalue() override
	{
		std::cout << "temp readV" << std::endl;
	}
	void calibrate() override
	{
		std::cout << "temp cali" << std::endl;
	}
};

class PressSensor : public ISensor
{
public:
	~PressSensor() override = default;

	float readvalue() override
	{
		std::cout << "press readV" << std::endl;
	}
	void calibrate() override
	{
		std::cout << "press cali" << std::endl;
	}
};

// 3. Factory pattern
class SensorFactory
{
public:
	static std::unique_ptr<ISensor> createTempSensor()
	{

		// return new TempSensor();
		return std::make_unique<TempSensor>();
	}

	static std::unique_ptr<ISensor>
	createPressSensor()
	{
		return std::make_unique<PressSensor>();
	}
};