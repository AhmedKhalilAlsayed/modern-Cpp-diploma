#include <iostream>
#include <memory>

class IShape
{
public:
	virtual float getArea() const = 0;

	virtual ~IShape() = default;
};

class Rectangle : public IShape
{
	float width_ = 0;
	float height_ = 0;

public:
	Rectangle(float w, float h) : width_(w), height_(h) {}
	float getArea() const override
	{
		return width_ * height_;
	}
};

class Square : public IShape
{
	float side_ = 0;

public:
	Square(float s) : side_(s) {}

	float getArea() const override
	{
		return side_ * side_;
	}
};

class Circle : public IShape
{
	float rad_ = 0;

public:
	Circle(float r) : rad_(r) {}
	float getArea() const override
	{
		return 3.14 * rad_ * rad_;
	}
};

/// @brief ////////////////////////
void printArea(const IShape &shape)
{
	std::cout << "Area = " << shape.getArea() << std::endl;
}
////////////////////////////////////

int main()
{

	Rectangle rect{123, 2};
	Square sq{3};

	printArea(sq);

	return 0;
}