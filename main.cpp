#include <iostream>
#include <memory>

class Sensor
{
public:
	void hi()
	{
		std::cout << "Hi... \n";
	}

	~Sensor()
	{
		std::cout << "Sensor dtor\n";
	}
};

std::unique_ptr<Sensor> get()
{
	// return std::unique_ptr<Sensor>();
	// return std::unique_ptr<Sensor>(new Sensor);
	return std::make_unique<Sensor>();
}

int main()
{
	// Sensor s = get();
	// s.hi();

	auto ptr = get();
	ptr->hi();

	return 0;
}