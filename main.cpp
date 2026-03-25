#include <iostream>
#include <string.h>
#include <utility>
#include "shared_ptr.cpp"

int main()
{
	SharedPtr sptr(new int{64});
	SharedPtr sptr2(std::move(sptr));

	std::cout << *sptr2 << std::endl;
	return 0;
}
