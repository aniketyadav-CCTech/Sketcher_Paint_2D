#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	ui(new Ui::MainWindow), colorMode(0.0f, 0.0f, 0.0f), treeWidget(nullptr)
{
	ui->setupUi(this);

	treeWidget = new QTreeWidget(centralWidget());
	treeWidget->setObjectName("treeWidget");
	treeWidget->setGeometry(QRect(12, 70, 199, this->height() - 120));
	treeWidget->setColumnCount(1);
	treeWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	treeWidget->headerItem()->setText(0, "List of Geometries");

	QScrollArea* scrollArea = new QScrollArea(centralWidget());
	scrollArea->setObjectName("scrollArea");
	scrollArea->setGeometry(treeWidget->width() + 21, 70, this->width() - 220, this->height() - 120);

	glWidget = new GLWidget(centralWidget());
	glWidget->setGeometry(QRect(scrollArea->x(), scrollArea->y(), 1300,1300));
	glWidget->setObjectName("glWidget");
	scrollArea->setWidget(glWidget);

	intersection = new Intersection();

	connect(ui->actionSave, &QAction::triggered, this, [this]() {
		QString filePath = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), "Png Files (*.png)");
		if (!filePath.isEmpty())
		{
			glWidget->grabFramebuffer().save(filePath);
		}
		});
	connect(ui->actionClose, &QAction::triggered, this, [this]() {
		QApplication::quit();
		});
	connect(glWidget, &GLWidget::geometryDrawn, this, &MainWindow::geometryDrawn);
	connect(treeWidget, &QTreeWidget::itemClicked, this, &MainWindow::on_treeWidget_itemClicked);
	connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &MainWindow::on_treeWidget_itemDoubleClicked);
	this->setWindowState(Qt::WindowMaximized);

}

MainWindow::~MainWindow()
{
	delete ui;
	delete treeWidget;
	delete glWidget;
	delete intersection;
}

void MainWindow::geometryDrawn(std::unordered_map<std::string, Geometry::IGeometry*> geomMap)
{
	this->geomMap = geomMap;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
	QGroupBox* colorButtonBox = centralWidget()->findChild<QGroupBox*>("colorButtons");
	colorButtonBox->setGeometry(QRect(this->width() - 220, 10, 210, 50));
	ui->cleanupButton->setGeometry(QRect(this->width() - 280, 15, 40, 40));
	treeWidget->setGeometry(QRect(12, 70, 199, this->height() - 120));
	QScrollArea* scrollArea = centralWidget()->findChild<QScrollArea*>("scrollArea");
	scrollArea->setGeometry(treeWidget->width() + 21, 70, this->width() - 220, this->height() - 120);
	QMainWindow::resizeEvent(event);
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
			lineMap.clear();
			for (auto item : treeWidget->selectedItems())
			{
				if (item->parent()) {
					Geometry::IGeometry* geom = geomMap[item->text(column).toStdString()];
					std::vector<Geometry::Line*> lineList;
					if (getLinesInGeometry(geom, lineList))
						lineMap[geom->geomID] = lineList;
				}
			}
			std::vector<Geometry::Point*> intersectionPoints;
			if (intersection->getLineIntersectionPoints(lineMap, intersectionPoints))
				for (auto point : intersectionPoints)
				{
					point->thickness = Geometry::REGULAR;
					point->setColor(colorMode);
					glWidget->addGeom(point);
					glWidget->update();
				}
		}
}

bool MainWindow::getLinesInGeometry(Geometry::IGeometry* geom, std::vector<Geometry::Line*>& lineList)
{
	switch (geom->type) {
	case Geometry::LineType:
	{
		lineList.push_back(dynamic_cast<Geometry::Line*>(geom));
		std::vector<Geometry::Line*> list;
		list.push_back(dynamic_cast<Geometry::Line*>(geom));
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
	if (lineList.empty())
		return false;
	else return true;
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem* item, int column)
{
	if (item->parent())
	{
		Geometry::IGeometry* geom = geomMap[item->text(0).toStdString()];
		if (treeWidget->selectedItems().contains(item))
			geom->thickness = Geometry::BOLD;
		else
		{
			std::vector<Geometry::Point*> points;
			std::vector<Geometry::Line*> lineList;
			if (getLinesInGeometry(geom, lineList))
				for (auto line : lineList)
				{
					if (intersection->intersectionPointsInLine(line, points))
						for (auto point : points)
						{
							lineMap.erase(point->geomID);
							glWidget->removeGeom(point);
						}
				}
			geom->thickness = Geometry::REGULAR;
			glWidget->paintGL();
			glWidget->update();
		}
		glWidget->paintGL();
	}
}

void MainWindow::on_cleanupButton_clicked()
{
	qDebug() << "Cleanup";
	geomMap.clear();
	lineMap.clear();
	delete intersection;
	intersection = new Intersection();
}

