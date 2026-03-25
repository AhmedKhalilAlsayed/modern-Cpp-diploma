#include <iostream>
#include <string.h>
#include <utility>
#include "wrapper.cpp"

int main()
{
	Wrapper p(new int);

	std::cout << sizeof(p) << std::endl;

	return 0;
}