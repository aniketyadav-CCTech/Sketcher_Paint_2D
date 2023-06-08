#include "GLWidget.h"
#include <QOpenGLFunctions>
#include <QScreen>

GLWidget::GLWidget(QWidget* parent)
	: QOpenGLWidget(parent), drawLine(false), mGeometry(nullptr)
{
}

GLWidget::GLWidget(float in_x_offset, float in_y_offset, float in_z_offset)
	: m_program(0)
	, m_frame(0)
{
	x_offset = in_x_offset;
	y_offset = in_y_offset;
	z_offset = in_z_offset;

	int function_domain = 360;
	for (int i = -function_domain; i <= function_domain; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			colors.push_back(1.0f);
		}
		vertices.push_back((static_cast<float>(i) / static_cast<float>(function_domain)) + x_offset);     //X component
		vertices.push_back((sin((i * PI) / 180) / 2) + y_offset);	//Y component
		vertices.push_back(z_offset);                             //Z component
	}
}

void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void GLWidget::paintGL()
{
	if (mGeometry != nullptr) {
		glBegin(GL_LINES);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
		Point s = mGeometry->getStartpoint();
		glVertex2f(s.getX(), s.getY());
		Point e = mGeometry->getEndpoint();
		glVertex2f(e.getX(), e.getY());
		glEnd();
		
	}
	//else
	//{
	//	glClear(GL_COLOR_BUFFER_BIT);

	//	glBegin(GL_TRIANGLES);
	//	glColor3f(0.0f, 0.0f, 0.0f);
	//	glVertex2f(-0.5f, -0.5f);
	//	glColor3f(0.0f, 0.0f, 0.0f);
	//	glVertex2f(0.5f, -0.5f);
	//	glColor3f(0.0f, 0.0f, 1.0f);
	//	glVertex2f(0.0f, 0.5f);
	//	glEnd();
	//}
}
void GLWidget::toggleLineDrawing(bool enabled)
{
	drawLine = enabled;
	update();
}

void GLWidget::render()
{
	const qreal retinaScale = devicePixelRatio();
	glViewport(0, 0, width() * retinaScale, height() * retinaScale);

	glClear(GL_COLOR_BUFFER_BIT);

	m_program->bind();

	QMatrix4x4 matrix;
	matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	matrix.translate(0, 0, -2);
	matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);

	m_program->setUniformValue(m_matrixUniform, matrix);

	GLfloat vertices[] = {
		0.0f, 0.707f,
		-0.5f, -0.5f,
		0.5f, -0.5f
	};

	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	m_program->release();

	++m_frame;
}

void GLWidget::setGeom(Line* geometry)
{
	mGeometry = geometry;
}

void GLWidget::setShapeColor()
{
	m_shapeColor = Qt::red;
}

std::string GLWidget::loadShader(std::string shader_path)
{
	//Retrieve the vert_shader/frag_shader source code from filePath
	std::string shader_code;
	std::ifstream shader_file;
	//Ensure ifstream objects can throw exceptions:
	shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		shader_file.open(shader_path);
		std::stringstream shader_stream;
		//Read file's buffer contents into streams
		shader_stream << shader_file.rdbuf();
		//Close file handlers
		shader_file.close();
		//Convert stream into string
		shader_code = shader_stream.str();
		///std::cout << "Vert code:\n" << vert_code << "\nFrag code:\n" << frag_code << std::endl;
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
	}

	return shader_code;
}
