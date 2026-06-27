#include <iostream>
#include <memory>
#include <unistd.h>

class Shape
{
public:
	virtual void draw() = 0;
};

class RasterCircle : public Shape
{
	// ...
};
class VectorCircle : public Shape
{
	// ...
};
class ModernCircle : public Shape
{
	// ...
};

int main()
{
	return 0;
}