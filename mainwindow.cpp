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

    openGLWidget = new GLWidget(this);
    openGLWidget->setGeometry(QRect(320, 10, 711, 541));
    button = new QPushButton("PushButton", ui->centralwidget);

    connect(button, &QPushButton::clicked, openGLWidget, &GLWidget::toggleLineDrawing);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(button);
    layout->addWidget(openGLWidget);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    
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

    delete line;
}

