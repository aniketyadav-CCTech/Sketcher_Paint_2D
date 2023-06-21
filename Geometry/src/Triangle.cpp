#include "Triangle.h"

using namespace Geometry;

#define M_PI 3.14159

Triangle::Triangle() :IGeometry(TriangleType)
{
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	type = TriangleType;
	mP1 = p1;
	mP2 = p2;
	mP3 = p3;
}

Triangle::Triangle(Point centerPoint, Point endPoint)
{
	float deltaX = centerPoint.getX() - endPoint.getX();
	float deltaY = centerPoint.getY() - endPoint.getY();
	//float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);
	mP1.setX(centerPoint.getX());
	mP1.setY(deltaY);
	mP2.setX(deltaX);
	mP2.setY(deltaY);
	mP3 = endPoint;
}

void Triangle::input()
{
	mP1.input();
	mP2.input();
	mP3.input();
}

void Triangle::display()
{
}

std::string Triangle::toString()
{
	std::stringstream returnStr;
	returnStr << geometryNames[type] << " : ("
		<< this->mP1.getX() << ", "
		<< this->mP1.getY() << ", "
		<< this->mP1.getZ() << "), ("
		<< this->mP2.getX() << ", "
		<< this->mP2.getY() << ", "
		<< this->mP2.getZ() << "), ("
		<< this->mP3.getX() << ", "
		<< this->mP3.getY() << ", "
		<< this->mP3.getZ() << ")" << std::endl;
	return returnStr.str();
}

void Triangle::getTriangle(std::array<Point, 3>& arr)
{
	arr[0] = mP1;
	arr[1] = mP2;
	arr[2] = mP3;
}

Point Triangle::getStartpoint()
{
	return centerPoint;
}

Point Triangle::getEndpoint()
{
	return mP3;
}

void Triangle::setStartPoint(Point start)
{
	centerPoint = start;
	mP1.setX(centerPoint.getX());
}

void Triangle::setEndPoint(Point end)
{
	float dx = end.getX() - centerPoint.getX();
	float dy = end.getY() - centerPoint.getY();
	float distance = sqrt(dx * dx + dy * dy);

	float sideLength = (float)(2.0 * distance / sqrt(3.0));

	float angle = atan2(end.getY() - centerPoint.getY(), end.getX() - centerPoint.getX());
	float angle1 = (float)(angle + 2.0 * M_PI / 3.0);
	float angle2 = (float)(angle - 2.0 * M_PI / 3.0);

	mP1.setX(centerPoint.getX() + sideLength * cos(angle2));
	mP1.setY(centerPoint.getY() + sideLength * sin(angle2));

	mP3.setX(centerPoint.getX() + sideLength * cos(angle));
	mP3.setY(centerPoint.getY() + sideLength * sin(angle));

	mP2.setX(centerPoint.getX() + sideLength * cos(angle1));
	mP2.setY(centerPoint.getY() + sideLength * sin(angle1));
}

std::vector<Geometry::Line*> Geometry::Triangle::getEdgeList()
{
	return std::vector<Geometry::Line*> {new Line(mP1, mP2), new Line(mP1, mP3), new Line(mP3, mP2)};
}
