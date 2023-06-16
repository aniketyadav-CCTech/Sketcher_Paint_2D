#include "IGeometry.h"

void IGeometry::setColor(float r, float g, float b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

void IGeometry::setColor(Color _color)
{
	color = _color;
}

Color IGeometry::getColor()
{
	return color;
}
