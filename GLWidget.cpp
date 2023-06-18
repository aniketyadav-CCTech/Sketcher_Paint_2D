#include "GLWidget.h"
#include <QOpenGLFunctions>
#include <QScreen>
#include <algorithm>
#include <unordered_map>


GLWidget::GLWidget(QWidget* parent)
	: QOpenGLWidget(parent),
	startPoint(nullptr),
	endPoint(nullptr),
	lineCounter(0),
	quadCounter(0),
	circleCounter(0),
	triangleCounter(0),
	polygonCounter(0),
	pencilCounter(0),
	currentMode(LineMode)
{
	tree = parent->findChild<QTreeWidget*>("treeWidget");
	addTopLevelItems();
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
			Line* line = static_cast<Line*>(geom);
			line->setStartPoint(*startPoint);
			line->setEndPoint(*endPoint);
			line->setColor(m_shapeColor);
			std::vector<float> lineVertices;
			addPointToVector(lineVertices, line->getStartpoint());
			addColorToVector(lineVertices, line->getColor());
			addPointToVector(lineVertices, line->getEndPoint());
			addColorToVector(lineVertices, line->getColor());
			mGeometryData.push_back(lineVertices);
			lineVertices.clear();
			addGeom(geom);
			lineCounter++;
			break;
		}
		case QuadMode:
		{
			Quad* quad = static_cast<Quad*>(geom);
			quad->setStartPoint(*startPoint);
			quad->setEndPoint(*endPoint);
			quad->setColor(m_shapeColor);
			std::vector<float> quadVerts;
			addPointToVector(quadVerts, quad->getStartpoint());
			addColorToVector(quadVerts, quad->getColor());
			addPointToVector(quadVerts, quad->getVertex2());
			addColorToVector(quadVerts, quad->getColor());
			addPointToVector(quadVerts, quad->getEndpoint());
			addColorToVector(quadVerts, quad->getColor());
			addPointToVector(quadVerts, quad->getVertex3());
			addColorToVector(quadVerts, quad->getColor());
			mGeometryData.push_back(quadVerts);
			addGeom(geom);
			quadCounter++;
			break;
		}
		case CircleMode:
		{
			Circle* circle = static_cast<Circle*>(geom);
			circle->mCenterPoint = (*startPoint);
			float deltaX = startPoint->getX() - endPoint->getX();
			float deltaY = startPoint->getY() - endPoint->getY();
			circle->mRadius = std::sqrt(deltaX * deltaX + deltaY * deltaY);
			circle->setColor(m_shapeColor);
			const int num_segments = 30;
			std::vector<float> circlePositions;
			for (int i = 0; i < num_segments; i++) {
				float theta = 2.0f * M_PI * float(i) / float(num_segments);
				Point p;
				p.setX(circle->getRadius() * cosf(theta) + circle->mCenterPoint.getX());
				p.setY(circle->getRadius() * sinf(theta) + circle->mCenterPoint.getY());
				addPointToVector(circlePositions, p);
				addColorToVector(circlePositions, circle->getColor());
			}
			mGeometryData.push_back(circlePositions);
			circlePositions.clear();
			addGeom(geom);
			circleCounter++;
			break;
		}
		case TriangleMode:
		{
			Triangle* triangle = static_cast<Triangle*>(geom);
			triangle->setStartPoint(*startPoint);
			triangle->setEndPoint(*endPoint);
			triangle->setColor(m_shapeColor);
			std::array<Point, 3> vertArray;
			std::vector<float> triangleVerts;
			triangle->getTriangle(vertArray);
			for (auto point : vertArray) {
				addPointToVector(triangleVerts, point);
				addColorToVector(triangleVerts, triangle->getColor());
			}
			mGeometryData.push_back(triangleVerts);
			triangleVerts.clear();
			addGeom(geom);
			triangleCounter++;
			break;
		}
		case PolygonMode:
		{
			polygonCounter++;
			break;
		}
		case PencilMode:
		{
			pencilCounter++;
			break;
		}
		default:
			break;
		}
		addGeomToTree();
		paintGL();
		emit geometryDrawn(geom);
		update();
	}
	QOpenGLWidget::mousePressEvent(event);
}

void GLWidget::addPointToVector(std::vector<float>& vect, const Point& point)
{
	vect.push_back(point.getX());
	vect.push_back(point.getY());
	vect.push_back(point.getZ());
}

void GLWidget::addColorToVector(std::vector<float>& vect, const Color& color)
{
	vect.push_back(color.r);
	vect.push_back(color.g);
	vect.push_back(color.b);
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

	//**************************
	QOpenGLShader* vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
	if (vertexShader->compileSourceCode(vertexShaderSource)) {
		qDebug() << "Vertex Shader Compilation Done";
	}

	QOpenGLShader* fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
	if (fragmentShader->compileSourceCode(fragmentShaderSource)) {
		qDebug() << "Fragment Shader Compilation Done";
	}
	m_program = new QOpenGLShaderProgram(this);
	m_program->addShader(vertexShader);
	m_program->addShader(fragmentShader);
	m_program->link();

	m_posAttr = m_program->attributeLocation("position");
	m_colAttr = m_program->attributeLocation("color");

	glGenBuffers(1, &m_Vbo);
	glGenBuffers(1, &m_Vbo_Col);
	glGenBuffers(1, &m_highlightVbo);
	m_Vao.create();
	m_Vao.bind();
	m_Vao.release();
	m_highlightVao.create();
	m_highlightVao.bind();
	m_highlightVao.release();
	//**************************
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_program->bind();
	for (int i = 0; i < mGeometryData.size(); i++)
	{
		QOpenGLVertexArrayObject::Binder vaoBinder(&m_Vao);

		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
		glBufferData(GL_ARRAY_BUFFER, mGeometryData[i].size() * sizeof(float), mGeometryData[i].data(), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo_Col);
		glBufferData(GL_ARRAY_BUFFER, mGeometryData[i].size() * sizeof(float), mGeometryData[i].data(), GL_STATIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glLineWidth(1.0f);
		glDrawArrays(GL_LINE_LOOP, 0, mGeometryData[i].size() / 6);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	update();

}

void GLWidget::addGeom(IGeometry* geometry)
{
	mGeometry.push_back(geometry);
}

void GLWidget::setColorMode(Color color)
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

void GLWidget::addGeomToTree()
{
	std::string text;
	switch (currentMode)
	{
	case LineMode:
	{
		QTreeWidgetItem* item = itemLine;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		text = "Line " + std::to_string(lineCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case QuadMode: {
		QTreeWidgetItem* item = itemQuad;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		text = "Quad " + std::to_string(quadCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case CircleMode: {
		QTreeWidgetItem* item = itemCircle;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		text = "Circle " + std::to_string(circleCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case TriangleMode: {
		QTreeWidgetItem* item = itemTriangle;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		text = "Triangle " + std::to_string(triangleCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case PolygonMode: {
		QTreeWidgetItem* item = itemPolygon;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		text = "Polygon " + std::to_string(polygonCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case PencilMode: {
		QTreeWidgetItem* item = itemPencil;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		text = "Pencil " + std::to_string(pencilCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	default:
		text = "";
		break;
	}
	geom->geomID = text;
}

void GLWidget::addTopLevelItems()
{
	itemLine = new QTreeWidgetItem(tree);
	itemQuad = new QTreeWidgetItem(tree);
	itemCircle = new QTreeWidgetItem(tree);
	itemTriangle = new QTreeWidgetItem(tree);
	itemPolygon = new QTreeWidgetItem(tree);
	itemPencil = new QTreeWidgetItem(tree);
	itemLine->setText(0, std::string("Line").c_str());
	itemQuad->setText(0, std::string("Quad").c_str());
	itemCircle->setText(0, std::string("Circle").c_str());
	itemTriangle->setText(0, std::string("Triangle").c_str());
	itemPolygon->setText(0, std::string("Polygon").c_str());
	itemPencil->setText(0, std::string("Pencil").c_str());
	tree->addTopLevelItem(itemLine);
	tree->addTopLevelItem(itemQuad);
	tree->addTopLevelItem(itemCircle);
	tree->addTopLevelItem(itemTriangle);
	tree->addTopLevelItem(itemPolygon);
	tree->addTopLevelItem(itemPencil);
}