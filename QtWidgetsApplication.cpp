#include "QtWidgetsApplication.h"

QtWidgetsApplication::QtWidgetsApplication(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit1->setStyleSheet("border-width:0;border-style:outset");
	ui.lineEdit2->setStyleSheet("border-width:0;border-style:outset");
}

QtWidgetsApplication::~QtWidgetsApplication()
{}
void QtWidgetsApplication::on_num_0_clicked() {
	expression1 += "0";
	ui.lineEdit1->setText(expression1);
	
}
void QtWidgetsApplication::on_num_1_clicked() {
	expression1 += "1";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_2_clicked() {
	expression1 += "2";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_3_clicked() {
	expression1 += "3";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_4_clicked() {
	expression1 += "4";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_5_clicked() {
	expression1 += "5";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_6_clicked() {
	expression1 += "6";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_7_clicked() {
	expression1 += "7";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_8_clicked() {
	expression1 += "8";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_9_clicked() {
	expression1 += "9";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_zuo_clicked() {
	expression1 += "(";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_you_clicked() {
	expression1 += ")";
	ui.lineEdit1->setText(expression1);
}void QtWidgetsApplication::on_num_jia_clicked() {
	expression1 += "+";
	ui.lineEdit1->setText(expression1);
}void QtWidgetsApplication::on_num_jian_clicked() {
	expression1 += "-";
	ui.lineEdit1->setText(expression1);
}void QtWidgetsApplication::on_num_cheng_clicked() {
	expression1 += "*";
	ui.lineEdit1->setText(expression1);
}void QtWidgetsApplication::on_num_chu_clicked() {
	expression1 += "/";
	ui.lineEdit1->setText(expression1);
}void QtWidgetsApplication::on_num_AC_clicked() {
	expression1.clear();
	ui.lineEdit1->clear();
	ui.lineEdit2->clear();
}void QtWidgetsApplication::on_num_tui_clicked() {
	expression1.chop(1);
	ui.lineEdit1->setText(expression1);
}void QtWidgetsApplication::on_num_dian_clicked() {
	expression1 += ".";
	ui.lineEdit1->setText(expression1);
}
void QtWidgetsApplication::on_num_dengyu_clicked() {
	expression2 = expression1;
	ui.lineEdit2->setText(expression2);
	all();
	ui.lineEdit1->setText(expression1);
}