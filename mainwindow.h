#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <unordered_map>

#include <QMainWindow>
#include <QOpenGLFunctions>
#include <QStringListModel>
#include <QTreeWidget>

#include "GLWidget.h"
#include "IGeometry.h"
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
	void on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column);


public slots:
	void geometryDrawn(std::unordered_map<std::string, Geometry::IGeometry*> geomMap);

private:
	std::vector<Geometry::Line*> getLinesInGeometry(Geometry::IGeometry* geom);

protected:
	void changeEvent(QEvent* event);

public:
	std::unordered_map<std::string, Geometry::IGeometry*> geomMap;
	Ui::MainWindow* ui;
	QTreeWidget* treeWidget;
	Geometry::Color colorMode;
	Intersection* intersection;
	GLWidget* glWidget;

private:
	std::unordered_map<std::string, std::vector<Geometry::Line*>> lineMap;
};
#endif // MAINWINDOW_H
