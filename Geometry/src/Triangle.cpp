#include "Triangle.h"

Triangle::Triangle(std::array<Point, 3> pts, std::array<Point, 3> normal) :IGeometry("Triangle")
{
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

void Triangle::addPoints(std::array<Point, 3>& points)
{
	//for (size_t i = 0; i < 3; i++)
	//	pts[i] = points[i];
}

void Triangle::addNormal(std::array<Point, 3>& normal)
{
	//for (size_t i = 0; i < 3; i++)
	//	mNormal[i] = normal[i];
}

void Triangle::addvertex(std::array<Vertex, 3>& vertex)
{
	for (size_t i = 0; i < 3; i++)
		pts[i] = vertex[i];
}
void Triangle::getTriangle(std::array<Vertex, 3>& arr)
{
	for (int i = 0; i < 3; i++)
	{
		arr[i].normal.setX(pts[i].normal.getX());
		arr[i].normal.setY(pts[i].normal.getY());
		arr[i].normal.setZ(pts[i].normal.getZ());
		arr[i].position.setX(pts[i].position.getX());
		arr[i].position.setY(pts[i].position.getY());
		arr[i].position.setZ(pts[i].position.getZ());
	}
}
