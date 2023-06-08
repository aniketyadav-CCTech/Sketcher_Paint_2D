#include "lineinputdialog.h"
#include <sstream>
#include "ui_lineinputdialog.h"
#include <QMessageBox>

LineInputDialog::LineInputDialog(QWidget* parent) :
	QDialog(parent), line(nullptr),
	ui(new Ui::LineInputDialog)
{
	ui->setupUi(this);
}

LineInputDialog::~LineInputDialog()
{
	delete ui;
}

Line* LineInputDialog::getLine()
{
	return line;
}




void LineInputDialog::on_buttonBox_accepted()
{
	try {
		float sX = this->findChild<QLineEdit*>("startX")->text().toFloat();
		float sY = this->findChild<QLineEdit*>("startY")->text().toFloat();
		float eX = this->findChild<QLineEdit*>("endX")->text().toFloat();
		float eY = this->findChild<QLineEdit*>("endY")->text().toFloat();
		Point p1 = Point(sX, sY, 0.0f);
		Point p2 = Point(eX, eY, 0.0f);
		Line* l = new Line(p1, p2);
		line = l;
		l = nullptr;
	}
	catch (char* e) {
		QMessageBox::warning(this, "Incorrect details", "Plaese try again with correct co-ordinates :"+ *e);
	}
}

