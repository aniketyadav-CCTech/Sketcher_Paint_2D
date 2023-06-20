#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	ui(new Ui::MainWindow), colorMode(0.0f, 0.0f, 0.0f)
{
	ui->setupUi(this);

	glWidget = new GLWidget(this);
	glWidget->setGeometry(QRect(220, 90, 791, 511));
	glWidget->setMinimumSize(QSize(0, 0));
	glWidget->setAutoFillBackground(false);

	connect(glWidget, &GLWidget::geometryDrawn, this, &MainWindow::geometryDrawn);
	//connect(treeWidget, &QTreeWidget::itemDeactivated, this, [this]() {});
	treeWidget = ui->treeWidget;
	connect(treeWidget, &QTreeWidget::itemDoubleClicked, this, &MainWindow::on_treeWidget_itemClicked);
	intersection = new Intersection();
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
		if (isMaximized()) {
			QSize windowSize = size();
			glWidget->resize(windowSize.width() - 250, windowSize.height() - 150);
		}
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

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem* item, int column)
{
	if(!item->parent() && treeWidget->selectedItems().size() != 0)
		treeWidget->selectedItems().pop_back();
	
	if (treeWidget->selectedItems().size() != 0)
		if (item->parent())
		{
			Geometry::IGeometry* geom = geomMap[item->text(column).toStdString()];
			geom->thickness = (treeWidget->selectedItems().contains(item)) ? Geometry::BOLD : Geometry::REGULAR;
			glWidget->paintGL();

			lineList.clear();
			for (auto item : treeWidget->selectedItems())
			{
				Geometry::IGeometry* geom = geomMap[item->text(column).toStdString()];
				if (geom->geomID._Starts_with("Line ")) {
					lineList.push_back(dynamic_cast<Geometry::Line*>(geom));
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


//void MainWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column)
//{
//	/*if (treeWidget->selectedItems().size() != 0) {
//		qDebug() << "(Double Click)Selected items : ";
//		for (auto item : treeWidget->selectedItems())
//			qDebug() << item->text(0).toStdString();
//		qDebug() << "}";
//	}*/
//	/*if (item->parent())
//	{
//
//	}*/
//}

