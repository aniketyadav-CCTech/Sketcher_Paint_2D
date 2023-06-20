#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "IGeometry.h"
#include "Point.h"

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

		float getRadius() { return (float)mRadius; };

	};
}
#endif // !CIRCLE_H