#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow), colorMode(0.0f, 0.0f, 0.0f)
{
	ui->setupUi(this);

	glWidget = new GLWidget(this);
	glWidget->setGeometry(QRect(220, 90, 791, 511));
	glWidget->setMinimumSize(QSize(0, 0));
	glWidget->setAutoFillBackground(false);

	connect(glWidget, &GLWidget::geometryDrawn, this, &MainWindow::geometryDrawn);
	//connect(treeWidget, &QTreeWidget::itemDeactivated, this, [this]() {});
	treeWidget = ui->treeWidget;
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::geometryDrawn(std::unordered_map<std::string, IGeometry*> geomMap)
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
}

void MainWindow::on_pencilButton_clicked()
{
}

void MainWindow::on_redColor_clicked()
{
	colorMode = Color(1.0f, 0.0f, 0.0f);
	glWidget->setColorMode(colorMode);
}

void MainWindow::on_blueColor_clicked()
{
	colorMode = Color(0.0f, 0.0f, 1.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_greenColor_clicked()
{
	colorMode = Color(0.0f, 1.0f, 0.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_blackColor_clicked()
{
	colorMode = Color(0.0f, 0.0f, 0.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_yellowColor_clicked()
{
	colorMode = Color(1.0f, 1.0f, 0.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_cyanColor_clicked()
{
	colorMode = Color(0.5f, 1.0f, 1.0f);
	glWidget->setColorMode(colorMode);

}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem* item, int column)
{
	if (item->parent())
	{
		if (treeWidget->selectedItems().contains(item)) {
			IGeometry* geom = geomMap[item->text(column).toStdString()];
			geom->thickness = BOLD;
			glWidget->sethighlitedGeometryData(geom);
			glWidget->update();
		}
		else
		{
			glWidget->sethighlitedGeometryData(nullptr);
		}
	}
}

