#pragma once
#ifndef IGEOMETRY_H
#define IGEOMETRY_H

#include<iostream>
#include<string>
#include "Export.h"
#include <vector>

namespace Geometry {

	enum GeometryType { LineType, QuadType, CircleType, TriangleType, PolygonType, PointType };

	struct DllExport Color {
		Color() : r(0), g(0), b(0) {}
		Color(float r, float g, float b) :r(r), g(g), b(b) {}
		float r; float g; float b;
	};
	enum BorderThickness
	{
		REGULAR = 1,
		BOLD = 2
	};

	class DllExport IGeometry
	{
	public:
		IGeometry() :type(LineType), color() { thickness = REGULAR; };
		IGeometry(GeometryType _type) {
			thickness = REGULAR;
			type = _type;
		}
		virtual void input() = 0;
		virtual void display() = 0;
		virtual std::string toString() = 0;
		virtual ~IGeometry() {};
		Color getColor();
		void setColor(float r, float g, float b);
		void setColor(Color _color);

	public:
		std::string geomID;
		GeometryType type;
		BorderThickness thickness;
		std::vector<float> geomData;

	protected:
		Color color;
		std::string geometryNames[6] = {
		"LineType",
		"QuadType",
		"CircleType",
		"TriangleType",
		"PolygonType",
		"PointType"
		};
	};
}
#endif // !IGEOMETRY_H