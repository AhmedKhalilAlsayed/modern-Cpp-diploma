#include <iostream>
#include <memory>

void swap(int &a, int &b)
{
	// int temp = a;
	// int temp = std::move(a);
	a = std::move(b);
	// b = temp;
}

int main()
{
	int x = 15;
	int y = 9;

	swap(x, y);
	y = 90;
	std::cout << x << '\n';
	std::cout << y << '\n';

	return 0;
}