#pragma once
#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtCore/qmath.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QTreeWidget>
#include <QOpenGLVertexArrayObject>

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "Line.h"
#include "Circle.h"
#include "Triangle.h"
#include "Quad.h"
#include "Polygon.h"

class MainWindow;

#define PI 3.141592653

enum DrawingMode { LineMode, QuadMode, CircleMode, TriangleMode, PolygonMode, PencilMode };

static const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"out vec4 color_out;\n"
"void main()\n"
"{\n"
"	 gl_PointSize = 7;\n"
"    gl_Position = vec4(position, 1.0);\n"
"    color_out = vec4(color, 1.0);\n"
"}";

static const char* fragmentShaderSource =
"#version 330 core\n"
"in vec4 color_out;\n"
"out vec4 fragColor;\n"
"uniform vec4 color;\n"
"void main()\n"
"{\n"
"    fragColor = color_out;\n"
"}";


class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions 
{
	Q_OBJECT

public:
	explicit GLWidget(QWidget* parent = nullptr);

	void initializeGL() override;
	void paintGL() override;
	void addGeom(Geometry::IGeometry* geometry);
	/**
	 * @brief Set current Drawing Mode
	 * @param mode geometry type
	*/
	void setDrawingMode(DrawingMode mode);
	/**
	 * @brief Set current Color mode
	 * @param color geometry color
	*/
	void setColorMode(Geometry::Color color);
	void drawGeom(Geometry::IGeometry* geom);

private:
	/**
	 * @brief Utility function to list Geometry ID to QTreeWidget
	*/
	void addGeomToTree();
	/**
	 * @brief Utility function to add QTreeWidget Top Level Items
	*/
	void addTopLevelItems();
	/**
	 * @brief Utility function to add Ponint to std::Vector<float>
	 * @param vect target std::vector<float>
	 * @param point	
	*/
	void addPointToVector(std::vector<float>& vect, const Geometry::Point& point);
	/**
	 * @brief Utility function to add Color to std::Vector<float>
	 * @param vect target std::vector<float>
	 * @param color 
	*/
	void addColorToVector(std::vector<float>& vect, const Geometry::Color& color);


protected:
	void resizeEvent(QResizeEvent* event) override;

signals:
	void geometryDrawn(std::unordered_map<std::string, Geometry::IGeometry*> geomMap);

private slots:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);



private:
	Geometry::IGeometry* geom;
	Geometry::Color m_shapeColor;
	DrawingMode currentMode;
	int lineCounter;
	int quadCounter;
	int circleCounter;
	int triangleCounter;
	int polygonCounter;
	int pencilCounter;
	std::vector<Geometry::Point*> mPolygonVertices;

	//*******************************
	GLuint m_posAttr;
	GLuint m_colAttr;
	QOpenGLShaderProgram* m_program;
	GLuint m_Vbo,m_Vbo_Col;
	QOpenGLVertexArrayObject m_Vao;
	std::unordered_map<std::string ,std::vector<float>> mGeometryData;
	std::unordered_map<std::string, Geometry::IGeometry*> geomMap;
	//*******************************

public:
	Geometry::Point* startPoint;
	Geometry::Point* endPoint;

	QTreeWidget* tree;
	QTreeWidgetItem* itemLine;
	QTreeWidgetItem* itemQuad;
	QTreeWidgetItem* itemCircle;
	QTreeWidgetItem* itemTriangle;
	QTreeWidgetItem* itemPolygon;
	QTreeWidgetItem* itemPencil;
};


#endif // !GLWIDGET_H
