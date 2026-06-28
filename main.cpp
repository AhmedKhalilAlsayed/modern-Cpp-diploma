#include <iostream>
#include <memory>
#include <unistd.h>

// render styles
class IRenderStyle
{
public:
	virtual void drawCircle(float x, float y, float redius) = 0;
	virtual void drawRect(float x, float y, float width, float height) = 0;
	virtual ~IRenderStyle() = default;
};

class RasterRenderStyle : public IRenderStyle
{

public:
	void drawCircle(float x, float y, float redius) override
	{
		std::cout << "Raster style: Circle" << std::endl;
	}
	void drawRect(float x, float y, float width, float height) override
	{
		std::cout << "Raster style: Rect" << std::endl;
	}
	~RasterRenderStyle() = default;
};

class VectorRenderStyle : public IRenderStyle
{

public:
	void drawCircle(float x, float y, float redius) override
	{
		std::cout << "Vector style: Circle" << std::endl;
	}
	void drawRect(float x, float y, float width, float height) override
	{
		std::cout << "Vector style: Rect" << std::endl;
	}
	~VectorRenderStyle() = default;
};

class IShape
{
protected:
	IRenderStyle &render;

public:
	IShape(IRenderStyle &r) : render(r) {}
	virtual void draw() = 0;
};

// shapes
class Circle : public IShape
{
public:
	Circle(IRenderStyle &r) : IShape(r) {}

	void draw() override
	{
		render.drawCircle(1, 1, 1);
	}
};
class Rectangle : public IShape
{

public:
	Rectangle(IRenderStyle &r) : IShape(r) {}

	void draw() override
	{
		render.drawRect(1, 1, 1, 1);
	}
};

int main()
{
	VectorRenderStyle vector;
	RasterRenderStyle raster;

	Circle circle{raster};
	circle.draw();

	return 0;
}