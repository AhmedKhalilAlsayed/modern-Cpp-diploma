#include <iostream>
#include <memory>
#include <unistd.h>

class INotifier
{
public:
	virtual void send(std::string &&msg) = 0;
	virtual ~INotifier() = default;
};

class EmailNotifier : public INotifier
{
public:
	void send(std::string &&msg) override
	{
		std::cout << "Email: " << msg << "\n";
	}
};

class SMSNotifier : public INotifier
{
public:
	void send(std::string &&msg) override
	{
		std::cout << "SMS: " << msg << "\n";
	}
};

class NotifierFactory
{
public:
	static std::unique_ptr<INotifier> create(std::string &type)
	{
		if (type == "email")
			return std::make_unique<EmailNotifier>();
		if (type == "sms")
			return std::make_unique<SMSNotifier>();

		return nullptr;
	}
};

int main()
{
	std::string type = "sms";
	auto n = NotifierFactory::create(type);

	if (n)
	{
		std::cout << "Formatting...\n";

		n->send("Hello World!");
		
		std::cout << "Logging...\n";
	}
	else
	{
		std::cerr << "Not Supported! \n";
	}
}