#include "Circle.h"
#include <sstream>

Circle::Circle() :IGeometry("Circle"), centerPoint(0, 0, 0), radius(0)
{
}

void Circle::input()
{
	std::cout << "Enter centerPoint" << std::endl;
	std::cin >> centerPoint;
	std::cout << "Enter radius" << std::endl;
	std::cin >> radius;
}

void Circle::display()
{
	std::cout << name << " : (" 
		<< this->centerPoint.getX() << ", "
		<< this->centerPoint.getY() << ", "
		<< this->centerPoint.getZ() << "), Radius : " 
		<< this->radius << std::endl;
}

std::string Circle::toString()
{
	std::stringstream ss;
	ss << name << " : ("
		<< this->centerPoint.getX() << ", "
		<< this->centerPoint.getY() << ", "
		<< this->centerPoint.getZ() << "), Radius : "
		<< this->radius;
	return ss.str();
}
