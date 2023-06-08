#ifndef LINEINPUTDIALOG_H
#define LINEINPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include "Line.h"

namespace Ui {
class LineInputDialog;
}

class LineInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LineInputDialog(QWidget *parent = nullptr);
    ~LineInputDialog();
    Line* getLine();

private slots:

    void on_buttonBox_accepted();
private:
    Ui::LineInputDialog *ui;
    Line* line;
};

#endif // LINEINPUTDIALOG_H
