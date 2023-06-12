#pragma once
#ifndef IGEOMETRY_H
#define IGEOMETRY_H

#include<iostream>
#include<string>
#include "Export.h"

class DllExport IGeometry
{
private:	
	
public:
	IGeometry():name("") {};
	IGeometry(std::string _name) {
		name = _name;
	}
	virtual void input() = 0;
	virtual void display()=0;
	virtual std::string toString()=0;
	virtual ~IGeometry() {};

public:
	std::string geomID;
	std::string name;
};
#endif // !IGEOMETRY_H