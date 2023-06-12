#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), colorMode(Black)
{
    ui->setupUi(this);

    glWidget = new GLWidget(this);
    glWidget->setGeometry(QRect(220, 90, 791, 511));
    glWidget->setMinimumSize(QSize(0, 0));
    glWidget->setAutoFillBackground(false);

    treeWidget = ui->treeWidget;
    ui->centralwidget->setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow()
{
    delete ui;
}



//void MainWindow::addChild(QTreeWidgetItem* TopLevelItem, std::string text)
//{
//    QTreeWidgetItem* child = new QTreeWidgetItem();
//    child->setText(0, text.c_str());
//    TopLevelItem->addChild(child);
//}

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

void MainWindow::updateListView()
{
    std::vector<IGeometry*> list = glWidget->getGeomList();
    //for(IGeometry* geom:sketches)
    QTreeWidgetItem* treeItem = new QTreeWidgetItem(ui->treeWidget);

}

void MainWindow::on_lineButton_clicked()
{
    glWidget->setDrawingMode(LineMode);
    glWidget->setShapeColor(colorMode);

    IGeometry* line = new Line();
    //count++;
    //line->geomID = "Line " + std::to_string(count);
    static_cast<Line*>(line)->setColor(colorMode.redF(), colorMode.greenF(), colorMode.blueF());
    glWidget->drawGeom(line);
    sketches.push_back(line);
    glWidget->paintGL();
}

void MainWindow::on_circleButton_clicked()
{
    glWidget->setDrawingMode(CircleMode);
    glWidget->setShapeColor(colorMode);

    IGeometry* circle = new Circle();
    static_cast<Circle*>(circle)->setColor(colorMode.redF(), colorMode.greenF(), colorMode.blueF());
    glWidget->drawGeom(circle);
    sketches.push_back(circle);
    glWidget->paintGL();
}

void MainWindow::on_rectangleButton_clicked()
{
    glWidget->setDrawingMode(QuadMode);
    glWidget->setShapeColor(colorMode);

    IGeometry* quad = new Quad();
    glWidget->drawGeom(quad);
    sketches.push_back(quad);
    glWidget->paintGL();
}

void MainWindow::on_triangleButton_clicked()
{
    glWidget->setDrawingMode(TriangleMode);
    glWidget->setShapeColor(colorMode);

    IGeometry* triangle = new Triangle();
    glWidget->drawGeom(triangle);
    sketches.push_back(triangle);
    glWidget->paintGL();
}

void MainWindow::on_polygonButton_clicked()
{
}

void MainWindow::on_pencilButton_clicked()
{
}

void MainWindow::on_redColor_clicked()
{
    colorMode = ColorMode::Red;
}

void MainWindow::on_blueColor_clicked()
{
    colorMode = ColorMode::Blue;
}

void MainWindow::on_greenColor_clicked()
{
    colorMode = ColorMode::Green;
}

void MainWindow::on_blackColor_clicked()
{
    colorMode = ColorMode::Black;
}

void MainWindow::on_yellowColor_clicked()
{
    colorMode = ColorMode::Yellow;
}


void MainWindow::on_cyanColor_clicked()
{
    colorMode = ColorMode::Cyan;
}

