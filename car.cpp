#include <iostream>
#include "car.hpp"

Car::Car(int id)
{

	this->id = id;
	tearsSpeed = new int[4];
}

Car::Car(const Car &copy)
{
	tearsSpeed = new int[4];
	// memcpy(tearsSpeed, copy.tearsSpeed, sizeof(int) * 4);
	for (size_t i = 0; i < 4; i++)
	{
		tearsSpeed[i] = copy.tearsSpeed[i];
	}
}

Car::~Car()
{

	delete[] tearsSpeed;
	tearsSpeed = nullptr;
}