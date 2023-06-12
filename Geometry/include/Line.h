#ifndef LINE_H
#define LINE_H
#include "IGeometry.h"
#include <sstream>
#include "Point.h"

class DllExport Line final: public IGeometry {
private:
	Point endpoint1, endpoint2;
	float m_colR, m_colG, m_colB;

public:
	Line();
	Line(const Point& _endpoint1,const Point& _endpoint2);

	void input() override;
	void display() override;
    std::string toString() override;
	void generateLine();
	Point getEndpoint();
	Point getStartpoint();
	void setStartPoint(Point start);
	void setEndPoint(Point end);
	void setColor(float r,float g, float b);
};

#endif
