#include "Point.h"
#include "Point.h"
#include <sstream>

using namespace Geometry;

Point::Point() :IGeometry(PointType)
{
    x = 0; y = 0; z = 0;
}

Point::Point(float _x, float _y, float _z) :
    x(_x), y(_y), z(_z)
{
    type = PointType;
}

Point::~Point()
{
}

void Point::input()
{
    std::cout << "Enter 3D Point " << std::endl;
    std::cin >> x >> y >> z;
}

void Point::display()
{
    std::cout << geometryNames[type] << " : " << this->x << "  " << this->y << "  " << this->z << std::endl;
}

std::string Point::toString()
{
    std::stringstream ss;
    ss << geometryNames[type] << " : " << this->x << "  " << this->y << "  " << this->z;
    return ss.str();
}

void Point::setGeomData()
{
    geomData.push_back(x);
    geomData.push_back(y);
    geomData.push_back(z);
    geomData.push_back(color.r);
    geomData.push_back(color.g);
    geomData.push_back(color.b);
}

void Point::setX(float _x) { x = _x; }
void Point::setY(float _y) { y = _y; }
void Point::setZ(float _z) { z = _z; }
float Point::getX() const { return x; }
float Point::getY() const { return y; }
float Point::getZ() const { return z; }

std::istream& Geometry::operator>>(std::istream& is, Point& point) {
    float x, y, z;
    is >> x >> y >> z;
    point.setX(x);
    point.setY(y);
    point.setZ(z);
    return is;
}

