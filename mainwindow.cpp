#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QOpenGLFunctions>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    openGLWidget = new GLWidget(this);
    /*setCentralWidget(openGLWidget);*/

    button = ui->lineButton;

    //button = new QPushButton("Toggle Line", this);
    connect(button, &QPushButton::clicked, openGLWidget, &GLWidget::toggleLineDrawing);

    //QVBoxLayout* layout = new QVBoxLayout;
    //layout->addWidget(button);
    //layout->addWidget(openGLWidget);

    //QWidget* centralWidget = new QWidget(this);
    //centralWidget->setLayout(layout);
    //setCentralWidget(centralWidget);
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::initializeGL()
//{
//    QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
//    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//}
//
//void MainWindow::resizeGL(int w, int h)
//{
//}
//
//void MainWindow::paintGL()
//{
//    glClearColor(0.35f, 0.28f, 0.29f, 0.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//}
//
//void MainWindow::resizeEvent(QResizeEvent* revent)
//{
//}
//
//void MainWindow::paintEvent(QPaintEvent* pevent)
//{
//}


void MainWindow::on_lineButton_clicked()
{
    LineInputDialog lineInputDialog;
    lineInputDialog.exec();
    Line* line = lineInputDialog.getLine();

    delete line;
}

