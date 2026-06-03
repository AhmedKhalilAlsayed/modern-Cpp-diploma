#include <iostream>
#include <memory>
#include <unistd.h>

// Factory

// product interface
class ITransport
{
public:
	virtual void deliver()
	{
		sleep(1); // init
	}
	virtual ~ITransport() = default;
};

// products
class Truck : public ITransport
{
public:
	void deliver() override
	{
		ITransport::deliver();

		std::cout << "Truck" << std::endl;
	}
};

class Ship : public ITransport
{
public:
	void deliver() override
	{
		ITransport::deliver();

		std::cout << "Ship" << std::endl;
	}
};

/////////////////

class TransportFactory
{
public:
	static std::unique_ptr<ITransport> create(std::string type)
	{
		if (type == "truck")
			return std::make_unique<Truck>();
		if (type == "ship")
			return std::make_unique<Ship>();
		return nullptr;
	}
};

/////////////////////////

int main()
{
	auto transport = TransportFactory::create("ship");

	if (transport)
	{
		std::cout << "Loading ... \n";
		transport->deliver();

		std::cout << "Done \n";
	}
	else
	{
		std::cerr << "Transport not supported!\n";
	}

	return 0;
}