#include "GLWidget.h"
#include <QOpenGLFunctions>
#include <QScreen>
#include <algorithm>


GLWidget::GLWidget(QWidget* parent)
	: QOpenGLWidget(parent), startPoint(nullptr), endPoint(nullptr)
{
	qDebug() << parent->objectName();
}

void GLWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		QPoint mousePos = event->pos();
		float x = static_cast<float>(mousePos.x());
		float y = static_cast<float>(height() - mousePos.y());
		float glX = (x / static_cast<float>(width())) * 2.0f - 1.0f;
		float glY = (y / static_cast<float>(height())) * 2.0f - 1.0f;
		startPoint = new Point(glX, glY, 0);
		if (endPoint != nullptr)
		{
			switch (currentMode)
			{
			case LineMode:
				geom = new Line();
				break;
			case QuadMode:
				geom = new Quad();
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
			static_cast<Line*>(geom)->setColor(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
			addGeom(geom);
			break;
		}
		case QuadMode:
		{
			static_cast<Quad*>(geom)->setStartPoint(*startPoint);
			static_cast<Quad*>(geom)->setEndPoint(*endPoint);
			static_cast<Quad*>(geom)->setColor(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
			addGeom(geom);
			break;
		}
		case CircleMode:
		{
			static_cast<Circle*>(geom)->mCenterPoint = (*startPoint);
			float deltaX = startPoint->getX() - endPoint->getX();
			float deltaY = startPoint->getY() - endPoint->getY();
			static_cast<Circle*>(geom)->mRadius = std::sqrt(deltaX * deltaX + deltaY * deltaY);
			static_cast<Circle*>(geom)->setColor(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
			addGeom(geom);
			break;
		}
		case TriangleMode:
			static_cast<Triangle*>(geom)->setStartPoint(*startPoint);
			static_cast<Triangle*>(geom)->setEndPoint(*endPoint);
			static_cast<Triangle*>(geom)->setColor(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
			addGeom(geom);
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
		resize(parentSize.width(), parentSize.height());
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
				circle->setColor(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
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
			if (geom->name == "Quad")
			{
				Quad* quad = dynamic_cast<Quad*>(geom);
				quad->setColor(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				glBegin(GL_LINE_LOOP);
				glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				Point s = quad->getStartpoint();
				Point v2 = quad->getVertex2();
				Point v3 = quad->getVertex3();
				Point e = quad->getEndpoint();
				glVertex2f(s.getX(), s.getY());
				glVertex2f(v2.getX(), v2.getY());
				glVertex2f(e.getX(), e.getY());
				glVertex2f(v3.getX(), v3.getY());
				glEnd();
				update();
			}
			if (geom->name == "Triangle")
			{
				Triangle* triangle = dynamic_cast<Triangle*>(geom);
				triangle->setColor(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				glBegin(GL_LINE_LOOP);
				glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				std::array<Point, 3> VertArray;
				triangle->getTriangle(VertArray);
				for(Point p : VertArray)
				glVertex2f(p.getX(), p.getY());
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

std::vector<IGeometry*> GLWidget::getGeomList()
{
	return mGeometry;
}



