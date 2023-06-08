#include "Line.h"
#include <sstream>

Line::Line():IGeometry("Line")
{
}

Line::Line(const Point& _endpoint1, const Point& _endpoint2):
	endpoint1(_endpoint1),endpoint2(_endpoint2)
{
}

void Line::input()
{
	endpoint1.input();
	endpoint2.input();
}

void Line::display()
{
	std::cout << name << " : ("
		<< this->endpoint1.getX() << ", "
		<< this->endpoint1.getY() << ", "
		<< this->endpoint1.getZ() << "), ("
		<< this->endpoint2.getX() << ", "
		<< this->endpoint2.getY() << ", "
		<< this->endpoint2.getZ() << ")"
		<< std::endl;
}

std::string Line::toString()
{
	std::stringstream returnStr;
	returnStr << name << " : ("
		<< this->endpoint1.getX() << ", "
		<< this->endpoint1.getY() << ", "
		<< this->endpoint1.getZ() << "), ("
		<< this->endpoint2.getX() << ", "
		<< this->endpoint2.getY() << ", "
		<< this->endpoint2.getZ() << ")";
		return returnStr.str();
}

void Line::generateLine()
{
}