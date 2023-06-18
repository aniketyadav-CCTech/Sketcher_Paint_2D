#include "Line.h"
#include "Line.h"
#include "Line.h"


Line::Line():IGeometry("Line")
{
}

Line::Line(const Point& _endpoint1, const Point& _endpoint2):
	endpoint1(_endpoint1),endpoint2(_endpoint2)
{
	name = "Line";
}

void Line::input()
{
	endpoint1.input();
	endpoint2.input();
}

void Line::display()
{	
	//glBegin(GL_LINES);
	////glColor3f(1.0f, 0.0f, 0.0f);
	//glColor3f(mColor.r,mColor.g,mColor.b);
	//Point s = this->getStartpoint();
	//glVertex2f(s.getX(), s.getY());
	//Point e = this->getEndpoint();
	//glVertex2f(e.getX(), e.getY());
	//glEnd();
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

Point Line::getEndPoint()
{
	return endpoint1;
}

void Line::setStartPoint(Point start)
{
	endpoint1 = start;
}

void Line::setEndPoint(Point end)
{
	endpoint2 = end;
}

Point Line::getStartpoint()
{
	return endpoint2;
}

