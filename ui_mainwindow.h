/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
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
    QGroupBox *geometrySelection;
    QPushButton *circleButton;
    QPushButton *triangleButton;
    QPushButton *polygonButton;
    QPushButton *pencilButton;
    QPushButton *lineButton;
    QPushButton *rectangleButton;
    QGroupBox *colorButtons;
    QPushButton *greenColor;
    QPushButton *blackColor;
    QPushButton *yellowColor;
    QPushButton *cyanColor;
    QPushButton *redColor;
    QPushButton *blueColor;
    QTreeWidget *treeWidget;
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
        MainWindow->setStyleSheet(QString::fromUtf8(""));
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
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        geometrySelection = new QGroupBox(centralwidget);
        geometrySelection->setObjectName("geometrySelection");
        geometrySelection->setGeometry(QRect(10, 10, 201, 51));
        geometrySelection->setStyleSheet(QString::fromUtf8("background-color: white;"));
        circleButton = new QPushButton(geometrySelection);
        circleButton->setObjectName("circleButton");
        circleButton->setGeometry(QRect(70, 10, 30, 30));
        circleButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        circleButton->setIcon(icon6);
        triangleButton = new QPushButton(geometrySelection);
        triangleButton->setObjectName("triangleButton");
        triangleButton->setGeometry(QRect(100, 10, 30, 30));
        triangleButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        triangleButton->setIcon(icon7);
        polygonButton = new QPushButton(geometrySelection);
        polygonButton->setObjectName("polygonButton");
        polygonButton->setGeometry(QRect(130, 10, 30, 30));
        polygonButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/polygon.png"), QSize(), QIcon::Normal, QIcon::Off);
        polygonButton->setIcon(icon8);
        pencilButton = new QPushButton(geometrySelection);
        pencilButton->setObjectName("pencilButton");
        pencilButton->setGeometry(QRect(160, 10, 30, 30));
        pencilButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        pencilButton->setIcon(icon9);
        lineButton = new QPushButton(geometrySelection);
        lineButton->setObjectName("lineButton");
        lineButton->setGeometry(QRect(10, 10, 30, 30));
        lineButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/line.png"), QSize(), QIcon::Normal, QIcon::Off);
        lineButton->setIcon(icon10);
        rectangleButton = new QPushButton(geometrySelection);
        rectangleButton->setObjectName("rectangleButton");
        rectangleButton->setGeometry(QRect(40, 10, 30, 30));
        rectangleButton->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/Resources/icons/rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        rectangleButton->setIcon(icon11);
        colorButtons = new QGroupBox(centralwidget);
        colorButtons->setObjectName("colorButtons");
        colorButtons->setGeometry(QRect(820, 10, 211, 51));
        colorButtons->setStyleSheet(QString::fromUtf8("background-color: white;"));
        greenColor = new QPushButton(colorButtons);
        greenColor->setObjectName("greenColor");
        greenColor->setGeometry(QRect(74, 10, 30, 30));
        greenColor->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(0, 255, 0);"));
        blackColor = new QPushButton(colorButtons);
        blackColor->setObjectName("blackColor");
        blackColor->setGeometry(QRect(106, 10, 30, 30));
        blackColor->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(0, 0, 0);"));
        yellowColor = new QPushButton(colorButtons);
        yellowColor->setObjectName("yellowColor");
        yellowColor->setGeometry(QRect(138, 10, 30, 30));
        yellowColor->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(255, 255, 0);"));
        cyanColor = new QPushButton(colorButtons);
        cyanColor->setObjectName("cyanColor");
        cyanColor->setGeometry(QRect(171, 10, 30, 30));
        cyanColor->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(0, 255, 255);"));
        redColor = new QPushButton(colorButtons);
        redColor->setObjectName("redColor");
        redColor->setGeometry(QRect(10, 10, 30, 30));
        redColor->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(255, 0, 0);"));
        blueColor = new QPushButton(colorButtons);
        blueColor->setObjectName("blueColor");
        blueColor->setGeometry(QRect(42, 10, 30, 30));
        blueColor->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(0, 0, 255);"));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(10, 70, 201, 521));
        treeWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1039, 26));
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
        geometrySelection->setTitle(QString());
        circleButton->setText(QString());
        triangleButton->setText(QString());
        polygonButton->setText(QString());
        pencilButton->setText(QString());
        lineButton->setText(QString());
        rectangleButton->setText(QString());
        colorButtons->setTitle(QString());
        greenColor->setText(QString());
        blackColor->setText(QString());
        yellowColor->setText(QString());
        cyanColor->setText(QString());
        redColor->setText(QString());
        blueColor->setText(QString());
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
