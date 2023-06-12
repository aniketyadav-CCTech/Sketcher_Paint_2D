QT       += core gui
QT       += opengl
QT       += openglwidgets
INCLUDEPATH += $$PWD/Geometry/include
INCLUDEPATH += $$PWD/Geometry/common/include
INCLUDEPATH += $$PWD
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
LIBS += -L$$PWD/Geometry/common/lib -lglew32s
LIBS += -L$$PWD/Geometry/common/lib -lglfw3
LIBS += -L$$PWD/Geometry/common/lib -lopengl32
LIBS += -L$$PWD/x64/Debug -lGeometry
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    GLWidget.cpp

HEADERS += \
    mainwindow.h \
    GLWidget.h

FORMS += \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    mainwindow.qrc

