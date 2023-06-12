#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::WindowStateChange) {
        if (isMaximized()) {
            QSize windowSize = size();
            ui->openGLWidget->resize(windowSize.width() / 2, windowSize.height() / 2);
        }
    }

    QMainWindow::changeEvent(event);
}

void MainWindow::on_lineButton_clicked()
{
    ui->openGLWidget->setDrawingMode(LineMode);
    
    IGeometry* line = new Line();//lineInputDialog->getLine();
    ui->openGLWidget->drawGeom(line);
    sketches.push_back(line);
    ui->openGLWidget->setShapeColor(Qt::red);
    ui->openGLWidget->paintGL();
}

void MainWindow::on_circleButton_clicked()
{
    ui->openGLWidget->setDrawingMode(CircleMode);

    IGeometry* circle = new Circle();
    ui->openGLWidget->drawGeom(circle);
    sketches.push_back(circle);
    ui->openGLWidget->setShapeColor(Qt::red);
    ui->openGLWidget->paintGL();
}



void MainWindow::on_rectangleButton_clicked()
{
}


void MainWindow::on_triangleButton_clicked()
{
}


void MainWindow::on_polygonButton_clicked()
{
}


void MainWindow::on_pencilButton_clicked()
{
}

