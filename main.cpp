#include <iostream>
#include <memory>
#include <unistd.h>

// render styles
class IRenderStyle
{
public:
	virtual void drawCircle(float x, float y, float redius) = 0;
	virtual void drawRect(float x, float y, float width, float height) = 0;
	virtual void drawTri(float x, float y, float width, float height) = 0;

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
	void drawTri(float x, float y, float width, float height) override
	{
		std::cout << "Raster style: Tri" << std::endl;
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
	void drawTri(float x, float y, float width, float height) override
	{
		std::cout << "Vector style: Tri" << std::endl;
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

	~IShape() = default;
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

class Triangle : public IShape
{
public:
	Triangle(IRenderStyle &r) : IShape(r) {}
	void draw() override
	{
		render.drawTri(1, 1, 1, 1);
	}
};

int main()
{
	VectorRenderStyle vector;
	RasterRenderStyle raster;

	Circle circle{raster};
	circle.draw();

	Triangle t{vector};
	t.draw();

	return 0;
}