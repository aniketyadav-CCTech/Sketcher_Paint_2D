#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "IGeometry.h"
#include "Point.h"


class DllExport Circle final: public IGeometry
{
public:
	Point mCenterPoint;
	double mRadius;
	Circle();
	Circle(Point centerPoint, float radius);

	void input() override;
	void display() override;
	std::string toString() override;
	
	float getRadius() { return mRadius; };
	void setColor(float r, float g, float b);


private:
	float m_colR, m_colG, m_colB;
};
#endif // !CIRCLE_H