#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GLWidget.h"
#include <lineinputdialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void initializeGL();
    //void resizeGL(int w, int h);
    //void paintGL();
    //void resizeEvent(QResizeEvent* revent);
    //void paintEvent(QPaintEvent* pevent);
private:
    GLWidget* openGLWidget;
    QPushButton* button;


private slots:
    void on_lineButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
