#include "Circle.h"
#include "Circle.h"
#include "Circle.h"
#include <sstream>

using namespace Geometry;

#define M_PI 3.14159

Circle::Circle() :IGeometry(CircleType), mCenterPoint(0, 0, 0), mRadius(0)
{
}

Circle::Circle(Point centerPoint, float radius) :
	mCenterPoint(centerPoint), mRadius(radius)
{
	this->type = CircleType;
}

void Circle::input()
{
	std::cout << "Enter center Point" << std::endl;
	std::cin >> mCenterPoint;
	std::cout << "Enter radius" << std::endl;
	std::cin >> mRadius;
}

void Circle::display()
{
	/*const int num_segments = 100;
	const float radius = 0.5f;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < num_segments; i++) {
		float theta = 2.0f * M_PI * float(i) / float(num_segments);
		float x = radius * cosf(theta);
		float y = radius * sinf(theta);
		glVertex2f(x, y);
	}
	glEnd();*/
}

std::string Circle::toString()
{
	std::stringstream ss;
	ss << geometryNames[type] << " : ("
		<< this->mCenterPoint.getX() << ", "
		<< this->mCenterPoint.getY() << ", "
		<< this->mCenterPoint.getZ() << "), Radius : "
		<< this->mRadius;
	return ss.str();
}

void Circle::addPoint(Point* point)
{
	pointsOnCircumferance.push_back(point);
	if (pointsOnCircumferance.size() > 1)
	{
		linesOnCircumferance.clear();
		for (size_t i = 0; i < pointsOnCircumferance.size() - 1; ++i) {
			Line* line = new Line;
			line->setStartPoint(*pointsOnCircumferance[i]);
			line->setEndPoint(*pointsOnCircumferance[i + 1]);
			linesOnCircumferance.push_back(line);
		}
		Line* line = new Line;
		line->setStartPoint(*pointsOnCircumferance.back());
		line->setEndPoint(*pointsOnCircumferance.front());
		linesOnCircumferance.push_back(line);
	}
}

std::vector<Line*> Geometry::Circle::getLines()
{
	return linesOnCircumferance;
}
