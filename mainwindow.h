#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QOpenGLFunctions>
#include "GLWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

protected:
	void changeEvent(QEvent* event);


private:
	std::vector<IGeometry*> sketches;
	Ui::MainWindow* ui;

protected:
	GLWidget* glWidget;
};
#endif // MAINWINDOW_H
