#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QOpenGLFunctions>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
    connect(ui->circlebutton, &QPushButton::clicked, this, &MainWindow::on_lineButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineButton_clicked()
{
    lineInputDialog = new LineInputDialog();
    lineInputDialog->setWindowTitle("Line Input");
    lineInputDialog->exec();
    IGeometry* line = lineInputDialog->getLine();
    sketches.push_back(line);
    ui->openGLWidget->setGeom(line);
    ui->openGLWidget->paintGL();
    ui->openGLWidget->update();
}
