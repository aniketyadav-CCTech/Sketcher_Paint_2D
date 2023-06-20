#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QOpenGLFunctions>
#include "GLWidget.h"
#include <QTreeWidget>
#include <QStringListModel>
#include "IGeometry.h"
#include <unordered_map>
#include "Intersection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum ColorMode { Red = Qt::red, Blue = Qt::blue, Green = Qt::green, Black = Qt::black, Yellow = Qt::yellow, Cyan = Qt::cyan };

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private slots:
	void on_lineButton_clicked();
	void on_circleButton_clicked();
	void on_rectangleButton_clicked();
	void on_triangleButton_clicked();
	void on_polygonButton_clicked();
	void on_pencilButton_clicked();
	void on_redColor_clicked();
	void on_blueColor_clicked();
	void on_greenColor_clicked();
	void on_blackColor_clicked();
	void on_yellowColor_clicked();
	void on_cyanColor_clicked();

	void on_treeWidget_itemClicked(QTreeWidgetItem* item, int column);

    //void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

public slots:
	void geometryDrawn(std::unordered_map<std::string, Geometry::IGeometry*> geomMap);

protected:
	void changeEvent(QEvent* event);

private:
	std::unordered_map<std::string, Geometry::IGeometry*> geomMap;


private:
	Ui::MainWindow* ui;
	QTreeWidget* treeWidget;
	Geometry::Color colorMode;
	Intersection* intersection;
	std::vector<Geometry::Line*> lineList;

protected:
	GLWidget* glWidget;
};
#endif // MAINWINDOW_H
