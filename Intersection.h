#pragma once
#include "IGeometry.h"
#include "Point.h"
#include "Line.h"
#include <QDebug>


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
	std::vector<Geometry::Point*> getLineIntersectionPoints(const std::vector<Geometry::IGeometry*>& lines);

private:
	int intersectionCounter;
};
