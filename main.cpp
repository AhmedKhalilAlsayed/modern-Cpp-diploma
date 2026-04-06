#include <iostream>
#include <string.h>
#include <utility>
#include <memory>

class UDT
{
public:
	UDT(int data) : data(data) {}
	int data = 0;
};

int main()
{

	// std::unique_ptr<UDT> ptr(new UDT);

	auto ptr = std::make_unique<int>(101);

	auto sptr = std::make_shared<int>(111);

	std::shared_ptr<int> p = std::shared_ptr<int>(new int);
	auto pp = std::make_unique<int>();
	std::unique_ptr<int> ppp = std::make_unique<int>();

	std::cout << sptr.get() << std::endl;
	return 0;
}
