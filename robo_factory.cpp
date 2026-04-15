#include <iostream>
#include <memory>

// product interface

class IMotor
{
public:
	virtual void move() = 0;
	virtual void stop() = 0;
	virtual ~IMotor() = default;
};
// concrete product

class DCMotor final : public IMotor
{
public:
	void move() override
	{
		std::cout << "DC motor moving" << std::endl;
	}
	void stop() override
	{
		std::cout << "DC motor stop" << std::endl;
	}
};
class StepperMotor final : public IMotor
{
public:
	void move() override
	{
		std::cout << "Stepper motor moving precisely" << std::endl;
	}
	void stop() override
	{
		std::cout << "Stepper motor stop" << std::endl;
	}
};

// product interface

class ISensor
{
public:
	virtual double read() = 0;
	virtual ~ISensor() = default;
};

// concrete product

class IRSensor final : public ISensor
{
public:
	double read() override
	{
		// simulated value
		return 15.5;
	}
};

class UltrasonicSensor final : public ISensor
{
public:
	double read() override
	{
		// simulated value
		return 30.2;
	}
};

// abstract factory
class IRobotFactory
{
public:
	virtual std::unique_ptr<IMotor> createMotor() = 0;
	virtual std::unique_ptr<ISensor> createSensor() = 0;
	virtual ~IRobotFactory() = default;
};

class BasicRobotFactory final : public IRobotFactory
{
public:
	std::unique_ptr<IMotor> createMotor() override
	{
		return std::make_unique<DCMotor>();
	}
	std::unique_ptr<ISensor> createSensor() override
	{
		return std::make_unique<IRSensor>();
	}
};

class AdvancedRobotFactory final : public IRobotFactory
{
public:
	std::unique_ptr<IMotor> createMotor() override
	{
		return std::make_unique<StepperMotor>();
	}
	std::unique_ptr<ISensor> createSensor() override
	{
		return std::make_unique<UltrasonicSensor>();
	}
};

//
class RobotBuilder
{
private:
	const std::unique_ptr<IRobotFactory> &factory_;

public:
	RobotBuilder(const std::unique_ptr<IRobotFactory> &factory)
		: factory_(factory)
	{
	}

	void buildAndTest()
	{
		// build
		auto motor = factory_.get()->createMotor();
		auto sensor = factory_.get()->createSensor();
		// test
		motor.get()->move();
		motor.get()->stop();

		std::cout << "sensor.get()->read(): " << sensor.get()->read() << std::endl
				  << std::endl;
	}
};