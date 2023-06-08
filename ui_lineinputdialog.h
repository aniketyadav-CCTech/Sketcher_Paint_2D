/********************************************************************************
** Form generated from reading UI file 'lineinputdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEINPUTDIALOG_H
#define UI_LINEINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_LineInputDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *startX;
    QLineEdit *startY;
    QLineEdit *endX;
    QLineEdit *endY;

    void setupUi(QDialog *LineInputDialog)
    {
        if (LineInputDialog->objectName().isEmpty())
            LineInputDialog->setObjectName("LineInputDialog");
        LineInputDialog->resize(400, 203);
        buttonBox = new QDialogButtonBox(LineInputDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 140, 341, 32));
        buttonBox->setInputMethodHints(Qt::ImhDigitsOnly);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(LineInputDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 101, 20));
        label_2 = new QLabel(LineInputDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 10, 101, 20));
        label_3 = new QLabel(LineInputDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 45, 21, 20));
        label_4 = new QLabel(LineInputDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 90, 21, 20));
        label_6 = new QLabel(LineInputDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(210, 86, 21, 20));
        label_7 = new QLabel(LineInputDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(210, 41, 21, 20));
        startX = new QLineEdit(LineInputDialog);
        startX->setObjectName("startX");
        startX->setGeometry(QRect(60, 40, 113, 25));
        startX->setInputMethodHints(Qt::ImhDigitsOnly);
        startY = new QLineEdit(LineInputDialog);
        startY->setObjectName("startY");
        startY->setGeometry(QRect(240, 40, 113, 25));
        startY->setInputMethodHints(Qt::ImhDigitsOnly);
        endX = new QLineEdit(LineInputDialog);
        endX->setObjectName("endX");
        endX->setGeometry(QRect(60, 90, 113, 25));
        endX->setInputMethodHints(Qt::ImhDigitsOnly);
        endY = new QLineEdit(LineInputDialog);
        endY->setObjectName("endY");
        endY->setGeometry(QRect(240, 90, 113, 25));
        endY->setInputMethodHints(Qt::ImhDigitsOnly);

        retranslateUi(LineInputDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, LineInputDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, LineInputDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(LineInputDialog);
    } // setupUi

    void retranslateUi(QDialog *LineInputDialog)
    {
        LineInputDialog->setWindowTitle(QCoreApplication::translate("LineInputDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LineInputDialog", "StartPoint", nullptr));
        label_2->setText(QCoreApplication::translate("LineInputDialog", "Endpoint", nullptr));
        label_3->setText(QCoreApplication::translate("LineInputDialog", "X :", nullptr));
        label_4->setText(QCoreApplication::translate("LineInputDialog", "Y :", nullptr));
        label_6->setText(QCoreApplication::translate("LineInputDialog", "Y :", nullptr));
        label_7->setText(QCoreApplication::translate("LineInputDialog", "X :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineInputDialog: public Ui_LineInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEINPUTDIALOG_H
