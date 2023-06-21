#include "Polygon.h"
#include "Polygon.h"

using namespace Geometry;

Polygon::Polygon() : IGeometry(PolygonType), mCenterPoint(nullptr), radius(0.0f)
{
}

Polygon::Polygon(std::vector<Point*> vertices): mCenterPoint(nullptr), radius(0.0f)
{
	type = PolygonType;
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

std::vector<Geometry::Line*> Polygon::getEdgeList()
{
	return edges;
}

std::string Polygon::toString()
{
	std::stringstream ss;
	ss << geometryNames[type] << " : "
		<< getEdgeCount();
	return ss.str();
}

void Geometry::Polygon::addVertex(Geometry::Point* point)
{
	vertices.push_back(point);
	if (vertices.size() > 1)
	{
		edges.clear();
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
}

