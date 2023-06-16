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
	pencilCounter(0)
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
			Line* line = static_cast<Line*>(geom);
			line->setStartPoint(*startPoint);
			line->setEndPoint(*endPoint);
			line->setColor(m_shapeColor);
			std::vector<float> lineVertices;
			lineVertices.push_back(line->getStartpoint().getX());
			lineVertices.push_back(line->getStartpoint().getY());
			lineVertices.push_back(line->getStartpoint().getZ());
			lineVertices.push_back(line->getColor().r);
			lineVertices.push_back(line->getColor().g);
			lineVertices.push_back(line->getColor().b);
			lineVertices.push_back(line->getEndpoint().getX());
			lineVertices.push_back(line->getEndpoint().getY());
			lineVertices.push_back(line->getEndpoint().getZ());
			lineVertices.push_back(line->getColor().r);
			lineVertices.push_back(line->getColor().g);
			lineVertices.push_back(line->getColor().b);
			mGeometryData.push_back(lineVertices);
			addGeom(geom);
			lineCounter++;
			break;
		}
		case QuadMode:
		{
			static_cast<Quad*>(geom)->setStartPoint(*startPoint);
			static_cast<Quad*>(geom)->setEndPoint(*endPoint);
			static_cast<Quad*>(geom)->setColor(m_shapeColor);
			addGeom(geom);
			quadCounter++;
			break;
		}
		case CircleMode:
		{
			static_cast<Circle*>(geom)->mCenterPoint = (*startPoint);
			float deltaX = startPoint->getX() - endPoint->getX();
			float deltaY = startPoint->getY() - endPoint->getY();
			static_cast<Circle*>(geom)->mRadius = std::sqrt(deltaX * deltaX + deltaY * deltaY);
			static_cast<Circle*>(geom)->setColor(m_shapeColor);
			addGeom(geom);
			circleCounter++;
			break;
		}
		case TriangleMode:
			static_cast<Triangle*>(geom)->setStartPoint(*startPoint);
			static_cast<Triangle*>(geom)->setEndPoint(*endPoint);
			static_cast<Triangle*>(geom)->setColor(m_shapeColor);
			addGeom(geom);
			triangleCounter++;
			break;
		case PolygonMode:
			polygonCounter++;
			break;
		case PencilMode:
			pencilCounter++;
			break;
		default:
			break;
		}
		addGeomToTree();
		paintGL();
		//update();
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
	if (!mGeometry.empty()) {
		std::unordered_map<std::string, DrawingMode> modeMap;
		modeMap["Line"] = LineMode;
		modeMap["Quad"] = QuadMode;
		modeMap["Circle"] = CircleMode;
		modeMap["Triangle"] = TriangleMode;
		modeMap["Polygon"] = PolygonMode;
		modeMap["Pencil"] = PencilMode;
		for (auto geom : mGeometry)
		{
			DrawingMode mode = modeMap[geom->name];
			switch (mode) {
			case LineMode:
			{
				Line* line = dynamic_cast<Line*>(geom);
				line->setColor(m_shapeColor);

				//glBegin(GL_LINES);
				//glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				//Point s = line->getStartpoint();
				//glVertex2f(s.getX(), s.getY());
				//Point e = line->getEndpoint();
				//glVertex2f(e.getX(), e.getY());
				//glEnd();
				//update();
				break;
			}
			case CircleMode:
			{
				Circle* circle = dynamic_cast<Circle*>(geom);
				circle->setColor(m_shapeColor);
				//const int num_segments = 100;
				//glBegin(GL_LINE_LOOP);
				//glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				//for (int i = 0; i < num_segments; i++) {
				//	float theta = 2.0f * M_PI * float(i) / float(num_segments);
				//	float x = circle->getRadius() * cosf(theta) + circle->mCenterPoint.getX();
				//	float y = circle->getRadius() * sinf(theta) + circle->mCenterPoint.getY();
				//	glVertex2f(x, y);
				//}
				//glEnd();
				//update();
				break;
			}
			case QuadMode:
			{
				Quad* quad = dynamic_cast<Quad*>(geom);
				quad->setColor(m_shapeColor);
				//glBegin(GL_LINE_LOOP);
				//glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				//Point s = quad->getStartpoint();
				//Point v2 = quad->getVertex2();
				//Point v3 = quad->getVertex3();
				//Point e = quad->getEndpoint();
				//glVertex2f(s.getX(), s.getY());
				//glVertex2f(v2.getX(), v2.getY());
				//glVertex2f(e.getX(), e.getY());
				//glVertex2f(v3.getX(), v3.getY());
				//glEnd();
				//update();
				break;
			}
			case TriangleMode:
			{
				Triangle* triangle = dynamic_cast<Triangle*>(geom);
				triangle->setColor(m_shapeColor);
				//glBegin(GL_LINE_LOOP);
				//glColor3f(m_shapeColor.redF(), m_shapeColor.greenF(), m_shapeColor.blueF());
				//std::array<Point, 3> VertArray;
				//triangle->getTriangle(VertArray);
				//for (Point p : VertArray)
				//	glVertex2f(p.getX(), p.getY());
				//glEnd();
				//update();
				break;
			}
			default:
				break;
			}
		}

		//**********************************
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}
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

		glDrawArrays(GL_LINES, 0, mGeometryData[i].size() / 2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	update();
	//**********************************

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
	switch (currentMode)
	{
	case LineMode:
	{
		QTreeWidgetItem* item = itemLine;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		std::string text = "Line " + std::to_string(lineCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case QuadMode: {
		QTreeWidgetItem* item = itemQuad;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		std::string text = "Quad " + std::to_string(quadCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case CircleMode: {
		QTreeWidgetItem* item = itemCircle;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		std::string text = "Circle " + std::to_string(circleCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case TriangleMode: {
		QTreeWidgetItem* item = itemTriangle;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		std::string text = "Triangle " + std::to_string(triangleCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case PolygonMode: {
		QTreeWidgetItem* item = itemPolygon;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		std::string text = "Polygon " + std::to_string(polygonCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	case PencilMode: {
		QTreeWidgetItem* item = itemPencil;
		QTreeWidgetItem* child = new QTreeWidgetItem();
		std::string text = "Pencil " + std::to_string(pencilCounter);
		child->setText(0, text.c_str());
		item->addChild(child);
		break;
	}
	default:
		break;
	}

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