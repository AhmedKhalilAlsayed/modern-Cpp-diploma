#include <iostream>
#include <string.h>
#include <utility>
#include "shared_ptr.cpp"
#include <memory>

void swapy(int &a, int &b)
{
	int temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

int main()
{
	int x = 5;
	int y = 50;

	swapy(x, y);

	return 0;
}
