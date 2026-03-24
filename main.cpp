#include <iostream>
#include "dynamic_array.cpp"

int main()
{
	DynamicArray arr(1);
	arr.pushBack(15);
	arr.pushBack(10);

	DynamicArray arrc(1);
	arrc = arr;
	//
	// arr.printArr();
	cout << arrc[0] << endl;
	cout << arrc[1] << endl;
	cout << arr.getArrLen() << endl;
	cout << arr.getArrSize() << endl;

	return 0;
}