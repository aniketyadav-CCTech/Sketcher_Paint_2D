#include "pointinputdialog.h"
#include "ui_pointinputdialog.h"

PointInputDialog::PointInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PointInputDialog)
{
    ui->setupUi(this);
}

PointInputDialog::~PointInputDialog()
{
    delete ui;
}

void PointInputDialog::on_buttonBox_accepted()
{

}

