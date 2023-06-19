#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QOpenGLFunctions>
#include "GLWidget.h"
#include <QTreeWidget>
#include <QStringListModel>
#include "IGeometry.h"
#include <unordered_map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum ColorMode { Red = Qt::red, Blue = Qt::blue, Green = Qt::green, Black = Qt::black, Yellow = Qt::yellow, Cyan = Qt::cyan};

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

    void on_treeWidget_itemActivated(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemSelectionChanged();

public slots:
	void geometryDrawn(std::unordered_map<std::string, IGeometry*> geomMap);

protected:
	void changeEvent(QEvent* event);

private:
	std::unordered_map<std::string, IGeometry*> geomMap;
	//void updateListView();
	//void addChild(QTreeWidgetItem* TopLevelItem, std::string text);


private:
	//std::vector<IGeometry*> sketches;
	Ui::MainWindow* ui;
	QTreeWidget* treeWidget;
	Color colorMode;
	//int count;
protected:
	GLWidget* glWidget;
};
#endif // MAINWINDOW_H
