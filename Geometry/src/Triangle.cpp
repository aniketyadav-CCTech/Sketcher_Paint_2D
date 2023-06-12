#include "Triangle.h"

Triangle::Triangle() :IGeometry("Triangle")
{
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	name = "Triangle";
	mP1 = p1;
	mP2 = p2;
	mP3 = p3;
}

void Triangle::input()
{
}

void Triangle::display()
{
}

std::string Triangle::toString()
{
	return this->name ;
}

void Triangle::getTriangle(std::array<Point, 3>& arr)
{
	arr[0] = mP1;
	arr[1] = mP2;
	arr[2] = mP3;
}
