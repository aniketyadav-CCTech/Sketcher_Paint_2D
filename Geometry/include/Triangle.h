#pragma once
#include "IGeometry.h"
#include "Point.h"
#include <sstream>
#include <array>

class DllExport Triangle final : public IGeometry
{
public:
    Triangle();
    Triangle(Point p1, Point p2, Point p3);
    Triangle(Point centerPoint, Point endPoint);
    std::string toString() override;
    void input() override;
    void display() override;
    void getTriangle(std::array<Point, 3>& arr);
    Point getStartpoint();
    Point getEndpoint();
    void setStartPoint(Point start);
    void setEndPoint(Point end);

private:
    Point centerPoint;
    Point mP1, mP2, mP3;
};
