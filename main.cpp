#include <iostream>
#include <memory>

class Base
{
public:
	virtual void show()
	{
		std::cout << "Hello Base" << std::endl;
	}
};

class Derived : public Base
{
public:
	void show() override
	{
		Base::show();

		// std::cout << "Hello Derived" << std::endl;
	}
};

int main()
{
	Derived b{};
	b.show();

	return 0;
}