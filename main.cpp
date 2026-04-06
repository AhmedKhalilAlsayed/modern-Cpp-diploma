#include <iostream>
#include <string.h>
#include <utility>
#include <memory>

class UDT
{
private:
	int data = 0;

public:
	UDT(/* args */);
	~UDT();
	static void print(std::weak_ptr<int> wptr)
	{
		// std::cout << wptr.use_count() << std::endl;
		std::cout << wptr.expired() << std::endl;

		auto sptr = wptr.lock();
		std::cout << sptr.get() << std::endl;
	}
};

UDT::UDT(/* args */)
{
	std::cout << "ctor" << std::endl;
}

UDT::~UDT()
{
	std::cout << "dtor" << std::endl;
}

class Free
{
public:
	void operator()(int *ptr)
	{
		free(ptr);
	}
};

int main()
{
	int *ptr = (int *)malloc(sizeof(int));
	auto uptr = std::unique_ptr<int, Free>(ptr, Free{});

	return 0;
}
