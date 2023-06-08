#pragma once
#include<iostream>
#include<string>
#include "Export.h"

class DllExport IGeometry
{
private:	
	
public:
	std::string name;
	IGeometry():name("") {};
	IGeometry(std::string name ) {
		this->name = name;
	}
	virtual void input() = 0;
	virtual void display()=0;
	virtual std::string toString()=0;
	virtual ~IGeometry() {};
};

