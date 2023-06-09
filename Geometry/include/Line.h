#ifndef LINE_H
#define LINE_H
#include "IGeometry.h"
#include <sstream>
#include "Point.h"

namespace Geometry
{
	class DllExport Line final : public IGeometry {
	private:
		Point endpoint1, endpoint2;

	public:
		Line();
		Line(const Point& _endpoint1, const Point& _endpoint2);

		void input() override;
		void display() override;
		std::string toString() override;
		void generateLine();
		Point getEndPoint() const;
		Point getStartPoint() const;
		void setStartPoint(Point start);
		void setEndPoint(Point end);
	};

}
#endif
