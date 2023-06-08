#pragma once
#include "IGeometry.h"
#include "Point.h"
#include <array>

class Vertex {
public:
    Point position;
    Point normal;
};

class DllExport Triangle final :
    public IGeometry
{
public:
    Triangle():IGeometry("Triangle") {}
    Triangle(std::array<Point, 3> pts, std::array<Point, 3> normal);
    void input() override;
    void display() override;
    std::string toString() override;
    void addPoints(std::array<Point, 3>& points);
    void addNormal(std::array<Point, 3>& normal);
    void addvertex(std::array<Vertex, 3>& vertex);
    void getTriangle(std::array<Vertex, 3>& arr);
private:
    std::array<Vertex, 3> pts;
    //std::array<Point, 3> pts;
    //std::array<Vec, 3> mNormal;
};

