#ifndef  POINT_H
#define  POINT_H

#include "IGeometry.h"

class DllExport Point final:public IGeometry
{
public:
	Point();
	Point(float _x, float _y, float _z);
	~Point();
	void input() override;
	void display() override;
	std::string toString() override;

	float getX();
	float getY();
	float getZ();
	void setX(float _x);
	void setY(float _y);
	void setZ(float _z);

private:
	float x, y, z;
};
DllExport std::istream& operator>>(std::istream& is, Point& point);

#endif // ! POINT_H