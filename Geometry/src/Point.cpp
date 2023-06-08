#include "Point.h"
#include <sstream>

Point::Point() :IGeometry("Point")
{
    x = 0; y = 0; z = 0;
}

Point::Point(float _x, float _y, float _z) :
    x(_x), y(_y), z(_z)
{
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
    std::cout << name << " : " << this->x << "  " << this->y << "  " << this->z << std::endl;
}

std::string Point::toString()
{
    std::stringstream ss;
    ss << name << " : " << this->x << "  " << this->y << "  " << this->z;
    return ss.str();
}

void Point::setX(float _x) { x = _x; }
void Point::setY(float _y) { y = _y; }
void Point::setZ(float _z) { z = _z; }
float Point::getX() { return x; }
float Point::getY() { return y; }
float Point::getZ() { return z; }

std::istream& operator>>(std::istream& is, Point& point) {
    float x, y, z;
    is >> x >> y >> z;
    point.setX(x);
    point.setY(y);
    point.setZ(z);
    return is;
}

