#include <iostream>

class Base
{
public:
	virtual void print() = 0;
};

class D1 : virtual public Base
{
public:
	void print() override
	{
		std::cout << "Hello 1" << std::endl;
	}
};

class D2 : virtual public Base
{
public:
	void print() override
	{
		std::cout << "Hello 2" << std::endl;
	}
};

class Diamon : public D1, public D2
{
public:
	void print() override
	{
		std::cout << "Hello 3" << std::endl;
	}
};

int main()
{
	Diamon d;
	d.print();

	return 0;
}