/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <GLWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionView_Help;
    QWidget *centralwidget;
    GLWidget *openGLWidget;
    QPushButton *lineButton;
    QPushButton *rectangleButton;
    QPushButton *circlebutton;
    QPushButton *triangleButton;
    QPushButton *polygonButton;
    QPushButton *pencilButton;
    QListWidget *listWidget;
    QFrame *line;
    QFrame *line_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1039, 643);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/close_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon2);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon3);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon4);
        actionView_Help = new QAction(MainWindow);
        actionView_Help->setObjectName("actionView_Help");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionView_Help->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        openGLWidget = new GLWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");
        openGLWidget->setGeometry(QRect(313, 78, 711, 511));
        openGLWidget->setMinimumSize(QSize(0, 0));
        lineButton = new QPushButton(centralwidget);
        lineButton->setObjectName("lineButton");
        lineButton->setGeometry(QRect(10, 10, 51, 51));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineButton->setIcon(icon6);
        rectangleButton = new QPushButton(centralwidget);
        rectangleButton->setObjectName("rectangleButton");
        rectangleButton->setGeometry(QRect(60, 10, 51, 51));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectangleButton->setIcon(icon7);
        circlebutton = new QPushButton(centralwidget);
        circlebutton->setObjectName("circlebutton");
        circlebutton->setGeometry(QRect(110, 10, 51, 51));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        circlebutton->setIcon(icon8);
        triangleButton = new QPushButton(centralwidget);
        triangleButton->setObjectName("triangleButton");
        triangleButton->setGeometry(QRect(160, 10, 51, 51));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        triangleButton->setIcon(icon9);
        polygonButton = new QPushButton(centralwidget);
        polygonButton->setObjectName("polygonButton");
        polygonButton->setGeometry(QRect(210, 10, 51, 51));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/polygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        polygonButton->setIcon(icon10);
        pencilButton = new QPushButton(centralwidget);
        pencilButton->setObjectName("pencilButton");
        pencilButton->setGeometry(QRect(261, 9, 51, 51));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        pencilButton->setIcon(icon11);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(13, 78, 271, 511));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(17, 60, 1001, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(286, 82, 20, 501));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1039, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionClose);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuHelp->addAction(actionView_Help);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionView_Help->setText(QCoreApplication::translate("MainWindow", "View Help", nullptr));
        lineButton->setText(QString());
        rectangleButton->setText(QString());
        circlebutton->setText(QString());
        triangleButton->setText(QString());
        polygonButton->setText(QString());
        pencilButton->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
