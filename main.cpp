#define GLEW_STATIC
#include <GL/glew.h>
//#include <GL/gl.h>
#include <glm/glm.hpp>
#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
