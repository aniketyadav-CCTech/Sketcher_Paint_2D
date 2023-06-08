/********************************************************************************
** Form generated from reading UI file 'pointinputdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTINPUTDIALOG_H
#define UI_POINTINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PointInputDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_X;
    QLineEdit *endX;
    QLineEdit *startX;
    QLabel *label_4;

    void setupUi(QDialog *PointInputDialog)
    {
        if (PointInputDialog->objectName().isEmpty())
            PointInputDialog->setObjectName("PointInputDialog");
        PointInputDialog->resize(243, 207);
        buttonBox = new QDialogButtonBox(PointInputDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 140, 211, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_X = new QLabel(PointInputDialog);
        label_X->setObjectName("label_X");
        label_X->setGeometry(QRect(40, 35, 21, 20));
        endX = new QLineEdit(PointInputDialog);
        endX->setObjectName("endX");
        endX->setGeometry(QRect(70, 80, 113, 25));
        endX->setInputMethodHints(Qt::ImhDigitsOnly);
        startX = new QLineEdit(PointInputDialog);
        startX->setObjectName("startX");
        startX->setGeometry(QRect(70, 30, 113, 25));
        startX->setInputMethodHints(Qt::ImhDigitsOnly);
        label_4 = new QLabel(PointInputDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 80, 21, 20));

        retranslateUi(PointInputDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PointInputDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PointInputDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PointInputDialog);
    } // setupUi

    void retranslateUi(QDialog *PointInputDialog)
    {
        PointInputDialog->setWindowTitle(QCoreApplication::translate("PointInputDialog", "Dialog", nullptr));
        label_X->setText(QCoreApplication::translate("PointInputDialog", "X :", nullptr));
        label_4->setText(QCoreApplication::translate("PointInputDialog", "Y :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PointInputDialog: public Ui_PointInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTINPUTDIALOG_H
