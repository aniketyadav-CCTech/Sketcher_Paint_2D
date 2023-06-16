#pragma once
#ifndef IGEOMETRY_H
#define IGEOMETRY_H

#include<iostream>
#include<string>
#include "Export.h"

struct DllExport Color {
	Color(): r(0), g(0), b(0) {}
	Color(float r, float g, float b):r(r),g(g),b(b){}
	float r; float g; float b;
};

class DllExport IGeometry
{
private:

public:
	IGeometry() :name(""),color() {};
	IGeometry(std::string _name) {
		name = _name;
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
	std::string name;
	Color color;
};
#endif // !IGEOMETRY_H