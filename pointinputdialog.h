#ifndef POINTINPUTDIALOG_H
#define POINTINPUTDIALOG_H

#include <QDialog>

namespace Ui {
class PointInputDialog;
}

class PointInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PointInputDialog(QWidget *parent = nullptr);
    ~PointInputDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::PointInputDialog *ui;
};

#endif // POINTINPUTDIALOG_H
