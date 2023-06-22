#include "Intersection.h"

Intersection::Intersection() : intersectionCounter(0)
{
}

bool Intersection::isEqualF(float x, float y)
{
	return fabs(x - y) < TOLERANCEL;
}

bool Intersection::isLessThanOrEqualToF(float x, float y)
{
	return (x - y) <= TOLERANCEL;
}

bool Intersection::isGreaterThanOrEqualToF(float x, float y)
{
	return (x - y) >= -TOLERANCEL;
}

bool Intersection::intersection(const Geometry::Line& line1, const Geometry::Line& line2, Geometry::Point& intersectionPoint)
{
	Geometry::Point p1 = line1.getStartPoint();
	Geometry::Point p2 = line1.getEndPoint();
	Geometry::Point p3 = line2.getStartPoint();
	Geometry::Point p4 = line2.getEndPoint();

	float x1 = p1.getX();
	float y1 = p1.getY();

	float x2 = p2.getX();
	float y2 = p2.getY();

	float x3 = p3.getX();
	float y3 = p3.getY();

	float x4 = p4.getX();
	float y4 = p4.getY();

	float denominator = ((x1 - x2) * (y3 - y4)) - ((y1 - y2) * (x3 - x4));

	// if lines are parallel
	if (isEqualF(denominator, 0.0f))
		return false;

	float numeratorX = ((x1 * y2) - y1 * x2) * (x3 - x4) - ((x1 - x2) * ((x3 * y4) - (y3 * x4)));
	float numeratorY = ((x1 * y2) - y1 * x2) * (y3 - y4) - ((y1 - y2) * ((x3 * y4) - (y3 * x4)));
	Geometry::Point* p = new Geometry::Point();
	p->setY(numeratorY / denominator);
	p->setX(numeratorX / denominator);

	if (isPointOnLineSegment(*p, line1) &&
		isPointOnLineSegment(*p, line2)) {
		if (isEndPoint(line1, p) || isEndPoint(line2, p)) // skip the endpoints of lines
			return false;
		intersectionPoint.setY(numeratorY / denominator);
		intersectionPoint.setX(numeratorX / denominator);
		return true;
	}
	return false;
}

std::vector<Geometry::Point*> Intersection::getLineIntersectionPoints(const std::vector<Geometry::IGeometry*>& lines)
{
	std::vector<Geometry::Point*> intersectionPoints;
	for (size_t i = 0; i < lines.size() - 1; i++) {
		for (size_t j = i + 1; j < lines.size(); j++) {
			Geometry::Point* intersectionP = new Geometry::Point();
			intersectionP->geomID = "Intersection " + std::to_string(++intersectionCounter);
			if (intersection(*dynamic_cast<Geometry::Line*>(lines[i]), *dynamic_cast<Geometry::Line*>(lines[j]), *intersectionP))
			{
				intersectionP->setGeomData();
				intersectionPoints.push_back(intersectionP);
			}
		}
	}
	return intersectionPoints;
}

bool Intersection::isPointOnLineSegment(const Geometry::Point& point, const Geometry::Line& lineSegment)
{
	float minX = std::min(lineSegment.getStartPoint().getX(), lineSegment.getEndPoint().getX());
	float maxX = std::max(lineSegment.getStartPoint().getX(), lineSegment.getEndPoint().getX());
	float minY = std::min(lineSegment.getStartPoint().getY(), lineSegment.getEndPoint().getY());
	float maxY = std::max(lineSegment.getStartPoint().getY(), lineSegment.getEndPoint().getY());

	return isGreaterThanOrEqualToF(point.getX(), minX)
		&& isLessThanOrEqualToF(point.getX(), maxX)
		&& isGreaterThanOrEqualToF(point.getY(), minY)
		&& isLessThanOrEqualToF(point.getY(), maxY);
}

bool Intersection::isEndPoint(const Geometry::Line& line, const Geometry::Point* point)
{
	if (line.getStartPoint().isEqual(*point) || line.getEndPoint().isEqual(*point))
		return true;

}
