#include "Polygon.h"
#include "Polygon.h"

using namespace Geometry;

Polygon::Polygon() : IGeometry("Polygon"), mCenterPoint(nullptr)
{
}

Polygon::Polygon(std::vector<Point*> vertices)
{
	name = "Polygon";
	for (size_t i = 0; i < vertices.size() - 1; ++i) {
		Line* line = new Line;
		line->setStartPoint(*vertices[i]);
		line->setEndPoint(*vertices[i + 1]);
		edges.push_back(line);
	}
	Line* line = new Line;
	line->setStartPoint(*vertices.back());
	line->setEndPoint(*vertices.front());
	edges.push_back(line);
}

Polygon::~Polygon()
{
}

void Polygon::input()
{
}

void Polygon::display()
{
}

size_t Polygon::getEdgeCount()
{
	return edges.size();
}

void Polygon::setCenterPoint(Point* point)
{
	mCenterPoint = point;
}

void Polygon::setCenterToVertexDistance(float distance)
{
	radius = distance;
}

std::string Polygon::toString()
{
	std::stringstream ss;
	ss << name << " : "
		<< getEdgeCount();
	return ss.str();
}

void Geometry::Polygon::addVertex(Geometry::Point* point)
{
	vertices.push_back(point);
}

