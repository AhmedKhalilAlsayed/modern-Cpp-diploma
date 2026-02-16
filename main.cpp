#include <iostream>
#include <string.h>
#include "car.hpp"
using namespace std;

class Builder
{
public:
	string str;

	Builder(string str)
	{
		this->str = str;
	}

	/* method channing */
	// void append(string copy){
	// Builder append(const string &copy)
	Builder &append(const string &copy)
	{
		str += copy;
		return *this;
	}
};

int main()
{
	Builder name("Ahmed ");

	// name.append("Khalil ").append("Al "); without & Al won't append
	name.append("Khalil ").append("Al ");

	cout << name.str << endl;

	return 0;
}