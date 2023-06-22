#pragma once
#include "IGeometry.h"
#include "Point.h"
#include "Line.h"
#include <QDebug>
#include <set>


#define TOLERANCEL 0.000001

class Intersection
{
public:
	Intersection();
	static bool isEqualF(float x, float y);
	static bool isLessThanOrEqualToF(float x, float y);
	static bool isGreaterThanOrEqualToF(float x, float y);

private:
	bool intersection(const Geometry::Line& line1, const Geometry::Line& line2, Geometry::Point& intersectionPoint);
	bool isPointOnLineSegment(const Geometry::Point& point, const Geometry::Line& lineSegment);
	bool isEndPoint(const Geometry::Line& line, const Geometry::Point* point);

public:
	std::vector<Geometry::Point*> getLineIntersectionPoints(const std::unordered_map<std::string, std::vector<Geometry::Line*>>& lines);
	std::vector<Geometry::Point*> intersectionPointsInLine(Geometry::Line* line);

private:
	int intersectionCounter;
	std::set<Geometry::Point*> m_IntersectionPoints;
};
