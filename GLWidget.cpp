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
			addPointToVector(line->geomData, line->getStartpoint());
			addColorToVector(line->geomData, line->getColor());
			addPointToVector(line->geomData, line->getEndPoint());
			addColorToVector(line->geomData, line->getColor());
			lineCounter++;
			addGeomToTree();
			mGeometryData[line->geomID] = line->geomData;
			addGeom(geom);
			break;
		}
		case QuadMode:
		{
			Quad* quad = static_cast<Quad*>(geom);
			quad->setStartPoint(*startPoint);
			quad->setEndPoint(*endPoint);
			quad->setColor(m_shapeColor);
			addPointToVector(quad->geomData, quad->getStartpoint());
			addColorToVector(quad->geomData, quad->getColor());
			addPointToVector(quad->geomData, quad->getVertex2());
			addColorToVector(quad->geomData, quad->getColor());
			addPointToVector(quad->geomData, quad->getEndpoint());
			addColorToVector(quad->geomData, quad->getColor());
			addPointToVector(quad->geomData, quad->getVertex3());
			addColorToVector(quad->geomData, quad->getColor());
			quadCounter++;
			addGeomToTree();
			mGeometryData[quad->geomID] = quad->geomData;
			addGeom(geom);
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
			for (int i = 0; i < num_segments; i++) {
				float theta = 2.0f * M_PI * float(i) / float(num_segments);
				Point p;
				p.setX(circle->getRadius() * cosf(theta) + circle->mCenterPoint.getX());
				p.setY(circle->getRadius() * sinf(theta) + circle->mCenterPoint.getY());
				addPointToVector(circle->geomData, p);
				addColorToVector(circle->geomData, circle->getColor());
			}
			circleCounter++;
			addGeomToTree();
			mGeometryData[circle->geomID] = circle->geomData;
			addGeom(geom);
			break;
		}
		case TriangleMode:
		{
			Triangle* triangle = static_cast<Triangle*>(geom);
			triangle->setStartPoint(*startPoint);
			triangle->setEndPoint(*endPoint);
			triangle->setColor(m_shapeColor);
			std::array<Point, 3> vertArray;
			triangle->getTriangle(vertArray);
			for (auto point : vertArray) {
				addPointToVector(triangle->geomData, point);
				addColorToVector(triangle->geomData, triangle->getColor());
			}
			triangleCounter++;
			addGeomToTree();
			mGeometryData[triangle->geomID] = triangle->geomData;
			addGeom(geom);
			break;
		}
		case PolygonMode:
		{
			polygonCounter++;
			addGeomToTree();
			break;
		}
		case PencilMode:
		{
			pencilCounter++;
			addGeomToTree();
			break;
		}
		default:
			break;
		}
		geomMap[geom->geomID] = geom;
		paintGL();
		emit geometryDrawn(geomMap);
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
	m_Vao.create();
	m_Vao.bind();
	m_Vao.release();
	glLineWidth(REGULAR);
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_program->bind();

	for (auto geomItem : mGeometryData)
	{
		IGeometry* geometry = geomMap[geomItem.first];
		std::vector<float> geometryData = geomItem.second;

		QOpenGLVertexArrayObject::Binder vaoBinder(&m_Vao);

		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
		glBufferData(GL_ARRAY_BUFFER, geometryData.size() * sizeof(float), geometryData.data(), GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, m_Vbo_Col);
		glBufferData(GL_ARRAY_BUFFER, geometryData.size() * sizeof(float), geometryData.data(), GL_DYNAMIC_DRAW);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);
		glLineWidth(geometry->thickness);
		glDrawArrays(GL_LINE_LOOP, 0, GLsizei(geometryData.size() / 6));
		glLineWidth(REGULAR);
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
	tree->addTopLevelItems({ itemLine, itemQuad, itemCircle, itemTriangle, itemPolygon, itemPencil });
}