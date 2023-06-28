#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <unordered_map>

#include <QMainWindow>
#include <QOpenGLFunctions>
#include <QStringListModel>
#include <QTreeWidget>
#include <QFileDialog>
#include <QScrollArea>

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
	/**
	 * @brief line geometry selection button click event handler
	*/
	void on_lineButton_clicked();
	/**
	 * @brief circle geometry selection button click event handler
	*/
	void on_circleButton_clicked();
	/**
	 * @brief rectangle geometry selection button click event handler
	*/
	void on_rectangleButton_clicked();
	/**
	 * @brief triangle geometry selection button click event handler
	*/
	void on_triangleButton_clicked();
	/**
	 * @brief polygon geometry selection button click event handler
	*/
	void on_polygonButton_clicked();
	/**
	 * @brief pencil geometry selection button click event handler
	*/
	void on_pencilButton_clicked();
	/**
	 * @brief red color mode selection button click event handler
	*/
	void on_redColor_clicked();
	/**
	 * @brief blue color mode selection button click event handler
	*/
	void on_blueColor_clicked();
	/**
	 * @brief green color mode selection button click event handler
	*/
	void on_greenColor_clicked();
	/**
	 * @brief black color mode selection button click event handler
	*/
	void on_blackColor_clicked();
	/**
	 * @brief yellow color mode selection button click event handler
	*/
	void on_yellowColor_clicked();
	/**
	 * @brief cyan color mode selection button click event handler
	*/
	void on_cyanColor_clicked();

	/**
	 * @brief cleanup sketch button click event handler
	*/
	void on_cleanupButton_clicked();

	/**
	 * @brief TreeWidget Item click event handler
	 * @param item item on which clicked
	 * @param column column on whick clicked
	*/
	void on_treeWidget_itemClicked(QTreeWidgetItem* item, int column);
	/**
	 * @brief TreeWidget Item double click event handler
	 * @param item item on which double clicked
	 * @param column column on whick double clicked
	*/
	void on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column);

public slots:
	/**
	 * @brief Event Handler for the new geometry drawn signal from GLWidget
	*/
	void geometryDrawn(std::unordered_map<std::string, Geometry::IGeometry*> geomMap);

private:
	/**
	 * @brief function for extracting vector of line segments in the Geometry
	 * @param geom Geometry from which lines to be extracted
	 * @param lineList std::vector of Line* to store the lines
	 * @return true if lines found in the geometry, false if there are no lines e.g. point
	*/
	bool getLinesInGeometry(Geometry::IGeometry* geom, std::vector<Geometry::Line*>& lineList);

protected:
	/**
	 * @brief Window Resize event handler
	 * @param event QResizeEvent* to store the event
	*/
	void resizeEvent(QResizeEvent* event) override;

public:
	/**
	 * @brief std::unordered_map of the geometries in the sketch mapped with their geomID's
	*/
	std::unordered_map<std::string, Geometry::IGeometry*> geomMap;
	/**
	 * @brief MainWindow* from QtCreator
	*/
	Ui::MainWindow* ui;
	/**
	 * @brief Pointer for the treeWidget
	*/
	QTreeWidget* treeWidget;
	/**
	 * @brief Active Color Mode
	*/
	Geometry::Color colorMode;
	/**
	 * @brief Intersection* for Calculating intersection between geometries
	*/
	Intersection* intersection;
	/**
	 * @brief QOpenGLWidget Inherited Class GLWidget* to show the sketch
	*/
	GLWidget* glWidget;

private:
	/**
	 * @brief std::unordered_map of lines in the sketch mapped with their geomID's
	*/
	std::unordered_map<std::string, std::vector<Geometry::Line*>> lineMap;
};
#endif // MAINWINDOW_H
