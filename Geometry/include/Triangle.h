#pragma once
#include "IGeometry.h"
#include "Point.h"
#include <array>

class DllExport Triangle final :
                                 public IGeometry
{
public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
    void input() override;
    void display() override;
    std::string toString() override;
    void getTriangle(std::array<Point, 3>& arr);
private:
    Point mP1, mP2, mP3;
};

