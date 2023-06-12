#pragma once
#ifndef IGEOMETRY_H
#define IGEOMETRY_H

#include<iostream>
#include<string>
#include "Export.h"

//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GL/gl.h>
//#include <glm/glm.hpp>

//#pragma comment(lib , "glew32.lib")
//#pragma comment(lib , "opengl32.lib")

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
#endif // !IGEOMETRY_H