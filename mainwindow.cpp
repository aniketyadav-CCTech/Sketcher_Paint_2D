#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GLWidget* glWidget = new GLWidget(this);//ui->openGLWidget;

    treeWidget = ui->treeWidget;
    addTopLevelItems();
    ui->centralwidget->setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTopLevelItems()
{
    itemLine = new QTreeWidgetItem(ui->treeWidget);
    itemQuad = new QTreeWidgetItem(ui->treeWidget);
    itemCircle = new QTreeWidgetItem(ui->treeWidget);
    itemTriangle = new QTreeWidgetItem(ui->treeWidget);
    itemPolygon = new QTreeWidgetItem(ui->treeWidget);
    itemPencil = new QTreeWidgetItem(ui->treeWidget);
    itemLine->setText(0, std::string("Line").c_str());
    itemQuad->setText(0, std::string("Quad").c_str());
    itemCircle->setText(0, std::string("Circle").c_str());
    itemTriangle->setText(0, std::string("Triangle").c_str());
    itemPolygon->setText(0, std::string("Polygon").c_str());
    itemPencil->setText(0, std::string("Pencil").c_str());
    treeWidget->addTopLevelItem(itemLine);
    treeWidget->addTopLevelItem(itemQuad);
    treeWidget->addTopLevelItem(itemCircle);
    treeWidget->addTopLevelItem(itemTriangle);
    treeWidget->addTopLevelItem(itemPolygon);
    treeWidget->addTopLevelItem(itemPencil);
}

void MainWindow::addChild(QTreeWidgetItem* TopLevelItem, std::string text)
{
    QTreeWidgetItem* child = new QTreeWidgetItem();
    child->setText(0, text.c_str());
    TopLevelItem->addChild(child);
}

void MainWindow::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::WindowStateChange) {
        if (isMaximized()) {
            QSize windowSize = size();
            ui->openGLWidget->resize(windowSize.width() - 250, windowSize.height() - 150);
        }
    }

    QMainWindow::changeEvent(event);
}

void MainWindow::updateListView()
{
    std::vector<IGeometry*> list = ui->openGLWidget->getGeomList();
    //for(IGeometry* geom:sketches)
    QTreeWidgetItem* treeItem = new QTreeWidgetItem(ui->treeWidget);

}

void MainWindow::on_lineButton_clicked()
{
    ui->openGLWidget->setDrawingMode(LineMode);
    ui->openGLWidget->setShapeColor(colorMode);
    
    IGeometry* line = new Line();
    count++;
    line->geomID = "Line " + std::to_string(count);
    static_cast<Line*>(line)->setColor(colorMode.redF(), colorMode.greenF(), colorMode.blueF());
    ui->openGLWidget->drawGeom(line);
    sketches.push_back(line);
    addChild(itemLine,line->geomID);
    ui->openGLWidget->paintGL();
}

void MainWindow::on_circleButton_clicked()
{
    ui->openGLWidget->setDrawingMode(CircleMode);
    ui->openGLWidget->setShapeColor(colorMode);

    IGeometry* circle = new Circle();
    static_cast<Circle*>(circle)->setColor(colorMode.redF(), colorMode.greenF(), colorMode.blueF());
    ui->openGLWidget->drawGeom(circle);
    sketches.push_back(circle);
    ui->openGLWidget->paintGL();
}

void MainWindow::on_rectangleButton_clicked()
{
    ui->openGLWidget->setDrawingMode(QuadMode);
    ui->openGLWidget->setShapeColor(colorMode);

    IGeometry* quad = new Quad();
    ui->openGLWidget->drawGeom(quad);
    sketches.push_back(quad);
    ui->openGLWidget->paintGL();
}

void MainWindow::on_triangleButton_clicked()
{
    ui->openGLWidget->setDrawingMode(TriangleMode);
    ui->openGLWidget->setShapeColor(colorMode);

    IGeometry* triangle = new Triangle();
    ui->openGLWidget->drawGeom(triangle);
    sketches.push_back(triangle);
    ui->openGLWidget->paintGL();
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

