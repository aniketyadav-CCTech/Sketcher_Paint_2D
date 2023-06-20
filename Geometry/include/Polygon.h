#pragma once
#include <vector>
#include "IGeometry.h"
#include "Line.h"
#include "Export.h"
#include "Point.h"

namespace Geometry
{
	class DllExport Polygon :
		public IGeometry
	{
	public:
		Polygon();
		Polygon(std::vector<Point*> vertices);
		~Polygon();
		void input() override;
		void display() override;
		std::string toString() override;
		void addVertex(Geometry::Point* point);
		size_t getEdgeCount();
		void setCenterPoint(Point* point);
		void setCenterToVertexDistance(float distance);

	private:
		std::vector<Line*> edges;
		std::vector<Point*> vertices;
		Point* mCenterPoint;
		float radius;
	};
}

