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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineButton_clicked()
{
    LineInputDialog lineInputDialog;
    lineInputDialog.exec();
    Line* line = lineInputDialog.getLine();
    ;
    delete line;
}

