#include "Quad.h"
#include "Quad.h"
#include "Quad.h"

using namespace Geometry;

Quad::Quad() :IGeometry(QuadType)
{
}

Quad::Quad(Point startPoint, Point endPoint)
	:m_StartPoint(startPoint),m_EndPoint(endPoint)
{
	m_Vertex2 = Point(startPoint.getY(), endPoint.getX(), 0);
	m_Vertex3 = Point(startPoint.getX(), endPoint.getY(), 0);
	type = QuadType;
}

Quad::~Quad()
{
}

void Quad::input()
{
	m_StartPoint.input();
	m_EndPoint.input();
}

void Quad::display()
{
	//TODO : Implement display for Quad
}

std::string Quad::toString()
{
	std::stringstream returnStr;
	returnStr << geometryNames[type] << " : ("
		<< this->m_StartPoint.getX() << ", "
		<< this->m_StartPoint.getY() << ", "
		<< this->m_StartPoint.getZ() << "), ("
		<< this->m_Vertex2.getX() << ", "
		<< this->m_Vertex2.getY() << ", "
		<< this->m_Vertex2.getZ() << "), ("
		<< this->m_Vertex3.getX() << ", "
		<< this->m_Vertex3.getY() << ", "
		<< this->m_Vertex3.getZ() << "), ("
		<< this->m_EndPoint.getX() << ", "
		<< this->m_EndPoint.getY() << ", "
		<< this->m_EndPoint.getZ() << ")" << std::endl;
	return returnStr.str();
}

void Quad::generateQuad()
{
}

Point Quad::getStartpoint()
{
	return m_StartPoint;
}

Point Quad::getEndpoint()
{
	return m_EndPoint;
}

Point Quad::getVertex2()
{
	return m_Vertex2;
}

Point Quad::getVertex3()
{
	return m_Vertex3;
}

void Quad::setStartPoint(Point start)
{
	m_Vertex2.setY(start.getY());
	m_Vertex3.setX(start.getX());
	m_StartPoint = start;
}

void Quad::setEndPoint(Point end)
{
	m_Vertex2.setX(end.getX());
	m_Vertex3.setY(end.getY());
	m_EndPoint = end;
}

std::vector<Geometry::Line*> Geometry::Quad::getEdgeList()
{
	return std::vector<Geometry::Line*> {
		new Line(m_StartPoint,m_Vertex2),
		new Line(m_Vertex2, m_EndPoint ),
		new Line(m_EndPoint,m_Vertex3),
		new Line(m_Vertex3, m_StartPoint)
	};
}


