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
    void setColor(float r, float g, float b);
private:
    Point centerPoint;
    Point mP1, mP2, mP3;
    float m_colR, m_colG, m_colB;
};

/*
//public:
Quad();
Quad(Point startPoint, Point endPoint);
~Quad();

void input() override;
void display() override;
std::string toString() override;

void generateQuad();
Point getStartpoint();
Point getEndpoint();
Point getVertex2();
Point getVertex3();
void setStartPoint(Point start);
void setEndPoint(Point end);
void setColor(float r, float g, float b);

private:
    Point m_StartPoint;
    Point m_EndPoint;
    Point m_Vertex2, m_Vertex3;
    float m_colR, m_colG, m_colB;

*/