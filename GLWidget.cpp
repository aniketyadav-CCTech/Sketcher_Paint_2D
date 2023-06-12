#include "GLWidget.h"
#include <QOpenGLFunctions>
#include <QScreen>
#include <algorithm>

GLWidget::GLWidget(QWidget* parent)
	: QOpenGLWidget(parent), startPoint(nullptr), endPoint(nullptr)
{
}

void GLWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		if (endPoint != nullptr)
		{
			switch (currentMode)
			{
			case LineMode:
				geom = new Line();
				break;
			case QuadMode:
				break;
			case CircleMode:
				geom = new Circle();
				break;
			case TriangleMode:
				geom = new Triangle();
				break;
			case PolygonMode:
				break;
			case PencilMode:
				break;
			default:
				break;
			}
		}
		QPoint mousePos = event->pos();
		float x = static_cast<float>(mousePos.x());
		float y = static_cast<float>(height() - mousePos.y());
		float glX = (x / static_cast<float>(width())) * 2.0f - 1.0f;
		float glY = (y / static_cast<float>(height())) * 2.0f - 1.0f;
		startPoint = new Point(glX, glY, 0);
	}
	QOpenGLWidget::mousePressEvent(event);
}


void GLWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {

		QPoint mousePos = event->pos();
		float glX = (2.0f * event->x() / width()) - 1.0f;
		float glY = 1.0f - (2.0f * event->y() / height());
		endPoint = new Point(glX, glY, 0);

		switch (currentMode)
		{
		case LineMode:
		{
			static_cast<Line*>(geom)->setStartPoint(*startPoint);
			static_cast<Line*>(geom)->setEndPoint(*endPoint);
			addGeom(geom);
			break;
		}
		case QuadMode:
			break;
		case CircleMode:
		{
			static_cast<Circle*>(geom)->mCenterPoint = (*startPoint);
			float deltaX = startPoint->getX() - endPoint->getX();
			float deltaY = startPoint->getY() - endPoint->getY();
			static_cast<Circle*>(geom)->mRadius = std::sqrt(deltaX * deltaX + deltaY * deltaY);
			addGeom(geom);
			break;
		}
		case TriangleMode:
			break;
		case PolygonMode:
			break;
		case PencilMode:
			break;
		default:
			break;
		}
		
		update();
	}
	QOpenGLWidget::mousePressEvent(event);
}

void GLWidget::resizeEvent(QResizeEvent* event)
{
	if (isMaximized()) {
		QSize parentSize = parentWidget()->size();
		resize(parentSize.width() / 2, parentSize.height() / 2);
	}

	QOpenGLWidget::resizeEvent(event);
}

void GLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void GLWidget::paintGL()
{
	if (!mGeometry.empty()) {
		for (auto geom : mGeometry)
		{
			if (geom->name == "Line")
			{
				Line* line = dynamic_cast<Line*>(geom);
				line->setColor(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				glBegin(GL_LINES);
				glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				Point s = line->getStartpoint();
				glVertex2f(s.getX(), s.getY());
				Point e = line->getEndpoint();
				glVertex2f(e.getX(), e.getY());
				glEnd();
				update();
			}
			if (geom->name == "Circle")
			{
				Circle* circle = dynamic_cast<Circle*>(geom);
				//circle->setColor(glm::vec3(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF()));
				//circle->display();
				const int num_segments = 100;
				glBegin(GL_LINE_LOOP);
				glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				for (int i = 0; i < num_segments; i++) {
					float theta = 2.0f * M_PI * float(i) / float(num_segments);
					float x = circle->getRadius() * cosf(theta) + circle->mCenterPoint.getX();
					float y = circle->getRadius() * sinf(theta) + circle->mCenterPoint.getY();
					glVertex2f(x, y);
				}
				glEnd();
				update();
			}
		}
	}
}

void GLWidget::addGeom(IGeometry* geometry)
{
	mGeometry.push_back(geometry);
}

void GLWidget::setShapeColor(QColor color)
{
	m_shapeColor = color;
}

void GLWidget::drawGeom(IGeometry* geom)
{
	this->geom = geom;
}

void GLWidget::setDrawingMode(DrawingMode mode)
{
	currentMode = mode;
}


