#pragma once

#include <QtCore/qmath.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Line.h"

#define PI 3.141592653

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions 
{
	Q_OBJECT

public:
	GLWidget(QWidget* parent = nullptr);
	GLWidget(float in_x_offset, float in_y_offset, float in_z_offset);
	void initializeGL() override;
	void paintGL() override;
	void render();
	void setGeom(IGeometry* geometry);
	void setShapeColor();
public slots:
	void toggleLineDrawing(bool enabled);

private:
	std::vector<IGeometry*> mGeometry;
	QColor m_shapeColor;
	bool drawLine;

	float x_offset, y_offset, z_offset;
	//Vector for holding coordinates
	std::vector<GLfloat> vertices;

	//Vector for the colors
	std::vector<GLfloat> colors;


	GLuint m_posAttr, m_colAttr;

	GLuint m_matrixUniform;
	QOpenGLShaderProgram* m_program;
	int m_frame;

	//Shader source variables
	std::string vertex_shader_source;
	std::string fragment_shader_source;

	//Utility function to read a text file into a string for the shader compiler
	std::string loadShader(std::string shader_path);
};

