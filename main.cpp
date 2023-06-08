#include "mainwindow.h"
#include "GLWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSurfaceFormat format;
    GLWidget wave_window(0, 0, 0);
    wave_window.setFormat(format);
    wave_window.resize(640, 480);
    wave_window.show();

    return a.exec();
}
