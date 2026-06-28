#include <iostream>
#include <memory>
#include <unistd.h>

// LED drivers
class ILEDDriver
{
public:
	virtual void on() = 0;
	virtual void off() = 0;

	~ILEDDriver() = default;
};

class GPIOLEDDriver : public ILEDDriver
{
public:
	void on() override
	{
		std::cout << "set pin HIGH" << std::endl;
	}
	void off() override
	{
		std::cout << "set pin LOW" << std::endl;
	}
};

class I2CLEDDriver : public ILEDDriver
{
public:
	void on() override
	{
		std::cout << "send to led addr HIGH" << std::endl;
	}
	void off() override
	{
		std::cout << "send to led addr LOW" << std::endl;
	}
};

// LED interface
class ILED
{
protected:
	ILEDDriver &driver_;

public:
	ILED(ILEDDriver &d) : driver_(d) {}

	virtual void on() = 0;
	virtual void off() = 0;

	virtual ~ILED() = default;
};

class LED : public ILED
{
public:
	LED(ILEDDriver &d) : ILED(d) {}

	void on() override
	{
		driver_.on();
	}
	void off() override
	{
		driver_.off();
	}
};

int main()
{
	GPIOLEDDriver gpioDriver;
	I2CLEDDriver i2cDriver;

	LED led{i2cDriver};

	led.on();

	return 0;
}