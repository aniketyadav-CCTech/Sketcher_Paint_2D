#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), colorMode(0.0f, 0.0f, 0.0f)
{
    ui->setupUi(this);

    glWidget = new GLWidget(this);
    glWidget->setGeometry(QRect(220, 90, 791, 511));
    glWidget->setMinimumSize(QSize(0, 0));
    glWidget->setAutoFillBackground(false);

    connect(glWidget, &GLWidget::geometryDrawn, this, &MainWindow::geometryDrawn);

    treeWidget = ui->treeWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::geometryDrawn(IGeometry* geom)
{
    geomMap[geom->geomID] = geom;
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

void MainWindow::on_treeWidget_itemActivated(QTreeWidgetItem *item, int column)
{
    qDebug() << "Item : " << item->text(column);
    if(item->text(column) != "Line" && item->text(column) != "Quad" &&
        item->text(column) != "Circle" && item->text(column) != "Triangle" &&
        item->text(column) != "Polygon" && item->text(column) != "Pencil")
    qDebug() << geomMap[item->text(column).toStdString()]->toString();
}

