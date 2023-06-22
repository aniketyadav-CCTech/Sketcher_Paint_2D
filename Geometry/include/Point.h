#ifndef  POINT_H
#define  POINT_H

#include "IGeometry.h"

namespace Geometry
{
#define TOLERANCEL 0.000001
	class DllExport Point final :public IGeometry
	{
	public:
		Point();
		Point(float _x, float _y, float _z);
		~Point();
		void input() override;
		void display() override;
		std::string toString() override;
		void setGeomData();
		float getX() const;
		float getY() const;
		float getZ() const;
		bool isEqual(const Point& other) const;
		void setX(float _x);
		void setY(float _y);
		void setZ(float _z);
	private:
		bool isEqualF(float x, float y) const;

	private:
		float x, y, z;
	};
	DllExport std::istream& operator>>(std::istream& is, Point& point);
}

#endif // ! POINT_H