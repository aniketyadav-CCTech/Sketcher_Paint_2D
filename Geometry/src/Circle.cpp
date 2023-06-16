#include "Circle.h"
#include "Circle.h"
#include <sstream>

#define M_PI 3.14159

Circle::Circle() :IGeometry("Circle"), mCenterPoint(0, 0, 0), mRadius(0)
{
}

Circle::Circle(Point centerPoint, float radius):
	mCenterPoint(centerPoint),mRadius(radius)
{
	this->name = "Circle";
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
	ss << name << " : ("
		<< this->mCenterPoint.getX() << ", "
		<< this->mCenterPoint.getY() << ", "
		<< this->mCenterPoint.getZ() << "), Radius : "
		<< this->mRadius;
	return ss.str();
}

