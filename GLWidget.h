#pragma once
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtCore/qmath.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <glm/glm.hpp>
#include "Line.h"
#include "Circle.h"
#include "Triangle.h"

#define PI 3.141592653

enum DrawingMode { LineMode, QuadMode, CircleMode, TriangleMode, PolygonMode, PencilMode };

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions 
{
	Q_OBJECT

public:
	explicit GLWidget(QWidget* parent = nullptr);
	void initializeGL() override;
	void paintGL() override;
	void addGeom(IGeometry* geometry);
	void setShapeColor(QColor color);
	Point* startPoint;
	Point* endPoint;
	void drawGeom(IGeometry* geom);
	void setDrawingMode(DrawingMode mode);

private slots:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

protected:
	void resizeEvent(QResizeEvent* event) override;

private:
	IGeometry* geom;
	std::vector<IGeometry*> mGeometry;
	QColor m_shapeColor;
	glm::vec3 color;
	DrawingMode currentMode;
};


#endif // !GLWIDGET_H