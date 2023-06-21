#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "IGeometry.h"
#include "Point.h"
#include "Line.h"

namespace Geometry
{
	class DllExport Circle final : public IGeometry
	{
	public:
		Point mCenterPoint;
		double mRadius;
		Circle();
		Circle(Point centerPoint, float radius);

		void input() override;
		void display() override;
		std::string toString() override;
		void addPoint(Point* point);
		std::vector<Line*> getLines();

		float getRadius() { return (float)mRadius; };

	private:
		std::vector<Point*> pointsOnCircumferance;
		std::vector<Line*> linesOnCircumferance;

	};
}
#endif // !CIRCLE_H