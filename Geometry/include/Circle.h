#pragma once

#include "IGeometry.h"
#include "Point.h"

class DllExport Circle final: public IGeometry
{
public:
	Point centerPoint;
	double radius;
	Circle();
	void input() override;
	void display() override;
	std::string toString() override;
};