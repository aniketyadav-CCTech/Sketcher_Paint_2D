#pragma once
#include "IGeometry.h"
#include <sstream>
#include "Point.h"

class DllExport Quad final :
    public IGeometry
{
public:
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

private:
    Point m_StartPoint;
    Point m_EndPoint;
    Point m_Vertex2, m_Vertex3;
};
