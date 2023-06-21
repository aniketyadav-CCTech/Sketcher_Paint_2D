#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	ui(new Ui::MainWindow), colorMode(0.0f, 0.0f, 0.0f), treeWidget(nullptr)
{
	ui->setupUi(this);

	treeWidget = new QTreeWidget(centralWidget());
	treeWidget->setObjectName("treeWidget");
	treeWidget->setGeometry(QRect(12, 70, 199, 521));
	treeWidget->setColumnCount(1);
	treeWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	treeWidget->headerItem()->setText(0, "List of Geometries");

	glWidget = new GLWidget(centralWidget());
	glWidget->setObjectName("glWidget");
	glWidget->setGeometry(QRect(220, 70, 1300, 1300));
	glWidget->setCursor(Qt::CrossCursor);

	intersection = new Intersection();

	connect(glWidget, &GLWidget::geometryDrawn, this, &MainWindow::geometryDrawn);
	connect(treeWidget, &QTreeWidget::itemClicked, this, &MainWindow::on_treeWidget_itemClicked);
	connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &MainWindow::on_treeWidget_itemDoubleClicked);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::geometryDrawn(std::unordered_map<std::string, Geometry::IGeometry*> geomMap)
{
	this->geomMap = geomMap;
}

void MainWindow::changeEvent(QEvent* event)
{
	if (event->type() == QEvent::WindowStateChange) {
		QSize windowSize = size(); 
		glWidget->setGeometry(QRect(220, 70, 1300, 1300));
		QGroupBox* colorButtonBox = centralWidget()->findChild<QGroupBox*>("colorButtons");
		colorButtonBox->setGeometry(QRect(centralWidget()->width() - 221, 10, 211, 51));
		treeWidget->setGeometry(QRect(12, 70, 199, centralWidget()->height() - 70));
	}
	QMainWindow::changeEvent(event);
}

void MainWindow::on_lineButton_clicked()
{
	glWidget->setDrawingMode(LineMode);
	glWidget->setColorMode(colorMode);
}

void MainWindow::on_circleButton_clicked()
{
	glWidget->setDrawingMode(CircleMode);
	glWidget->setColorMode(colorMode);
}

void MainWindow::on_rectangleButton_clicked()
{
	glWidget->setDrawingMode(QuadMode);
	glWidget->setColorMode(colorMode);
}

void MainWindow::on_triangleButton_clicked()
{
	glWidget->setDrawingMode(TriangleMode);
	glWidget->setColorMode(colorMode);
}

void MainWindow::on_polygonButton_clicked()
{
	glWidget->setDrawingMode(PolygonMode);
	glWidget->setColorMode(colorMode);
}

void MainWindow::on_pencilButton_clicked()
{
	glWidget->setDrawingMode(PencilMode);
	glWidget->setColorMode(colorMode);
}

void MainWindow::on_redColor_clicked()
{
	colorMode = Geometry::Color(1.0f, 0.0f, 0.0f);
	glWidget->setColorMode(colorMode);
}

void MainWindow::on_blueColor_clicked()
{
	colorMode = Geometry::Color(0.0f, 0.0f, 1.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_greenColor_clicked()
{
	colorMode = Geometry::Color(0.0f, 1.0f, 0.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_blackColor_clicked()
{
	colorMode = Geometry::Color(0.0f, 0.0f, 0.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_yellowColor_clicked()
{
	colorMode = Geometry::Color(1.0f, 1.0f, 0.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_cyanColor_clicked()
{
	colorMode = Geometry::Color(0.5f, 1.0f, 1.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
	if (treeWidget->selectedItems().size() != 0)
		if (item->parent())
		{
			std::vector<Geometry::IGeometry*> lineList;
			for (auto item : treeWidget->selectedItems())
			{
				if (item->parent()) {
					Geometry::IGeometry* geom = geomMap[item->text(column).toStdString()];
					switch (geom->type) {
					case Geometry::LineType:
					{
						lineList.push_back(dynamic_cast<Geometry::Line*>(geom));
						break;
					}
					case Geometry::QuadType:
					{
						Geometry::Quad* quad = dynamic_cast<Geometry::Quad*>(geom);
						for (auto line : quad->getEdgeList())
							lineList.push_back(line);
						break;
					}
					break;
					case Geometry::CircleType:
					{
						Geometry::Circle* circle = dynamic_cast<Geometry::Circle*>(geom);
						for (auto line : circle->getLines())
							lineList.push_back(line);
						break;
					}
					case Geometry::TriangleType:
					{
						Geometry::Triangle* triangle = dynamic_cast<Geometry::Triangle*>(geom);
						for (auto line : triangle->getEdgeList())
							lineList.push_back(line);
						break;
					}
					case Geometry::PolygonType:
					{
						Geometry::Polygon* polygon = dynamic_cast<Geometry::Polygon*>(geom);
						for (auto line : polygon->getEdgeList())
							lineList.push_back(line);
						break;
					}
					case Geometry::PointType:
						break;
					default:
						break;
					}
				}
			}
			std::vector<Geometry::Point*> intersectionPoints = intersection->getLineIntersectionPoints(lineList);
			for (auto& item : intersectionPoints)
			{
				Geometry::IGeometry* point = item;
				point->thickness = Geometry::REGULAR;
				point->setColor(colorMode);
				glWidget->addGeom(point);
				glWidget->paintGL();
				glWidget->update();
			}
		}
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem* item, int column)
{
	if (item->parent())
	{
		Geometry::IGeometry* geom = geomMap[item->text(0).toStdString()];
		geom->thickness = (treeWidget->selectedItems().contains(item)) ? Geometry::BOLD : Geometry::REGULAR;
		glWidget->paintGL();
	}
}

