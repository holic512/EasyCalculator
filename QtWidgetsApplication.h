#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication.h"
#include <qstring.h>
#include <qstack.h>
class QtWidgetsApplication : public QWidget
{
	Q_OBJECT

public:
	QtWidgetsApplication(QWidget* parent = nullptr);
	~QtWidgetsApplication();

	void all() {
		char* info;
		QByteArray ba = expression1.toLatin1(); 
		info = ba.data();
		for (int i = 0; i < strlen(info); i++) {
			//�ж��Ƿ�Ϊ����
			if (info[i] >= '0' && info[i] <= '9') {
				num.push((double)info[i] - 48);
				//�ж��Ƿ�Ϊ��λ��
				i++;
				int a = 1;
				double n;
				while (info[i] >= '0' && info[i] <= '9') {
					n = num.top();
					n *= 10;
					n += info[i] - 48;
					a++;
					i++;
					num.pop();
					num.push(n);
				}
				i--;
			}
			//�ж��Ƿ�ΪС����
			else if (info[i] == '.') {
				int a = 1;
				double n;
				i++;
				while (info[i] >= '0' && info[i] <= '9') {
					n = ((double)info[i] - 48);
					for (int decimal = 0; decimal < a; decimal++) {
						n *= 0.1;
					}
					a++;
					i++;
					n += num.top();
					num.pop();
					num.push(n);
				}
				i--;
			}
			//�ж��Ƿ�Ϊ����
			else if (info[i] == '+' || info[i] == '-' || info[i] == '*' || info[i] == '/' || info[i] == '(' || info[i] == ')') {
				//�ж�ջ�Ƿ�Ϊ��
				if (s.empty()) s.push(info[i]);//Ϊ����ֱ�ӽ�վ
				else { //��������������ȼ�С�ڻ������һ�����ȼ� ��������ȼ�
					if ((info[i] == ')' && s.top() == '(')) s.pop();
					else if (info[i] == '(' || s.top() == '(' || (info[i] == '*' || info[i] == '/') && (s.top() == '+' || s.top() == '-'))s.push(info[i]);
					else {
						double n1 = num.top();
						num.pop();
						double n2 = num.top();
						num.pop();
						char opera = s.top();
						s.pop();
						num.push(operation(n1, n2, opera));
						s.push(info[i]);
					}
				}

			}
		}
		while (!s.empty()) {
			char opera = s.top();
			s.pop();
			if (opera != '(' && opera != ')') {
				double n1 = num.top();
				num.pop();
				double n2 = num.top();
				num.pop();
				num.push(operation(n1, n2, opera));
			}
		}
		expression1 = QString::number(num.top());
		num.pop();
	}
	//�������㺯��
	double operation(double n1, double n2, char opera) {
		switch (opera) {
		case '+':
			return n2 + n1;
		case'-':
			return n2 - n1;
		case'*':
			return n2 * n1;
		case'/':
			return n2 / n1;
		}
	}


private slots:
	void on_num_0_clicked();
	void on_num_1_clicked();
	void on_num_2_clicked();
	void on_num_3_clicked();
	void on_num_4_clicked();
	void on_num_5_clicked();
	void on_num_6_clicked();
	void on_num_7_clicked();
	void on_num_8_clicked();
	void on_num_9_clicked();
	void on_num_zuo_clicked();
	void on_num_you_clicked();
	void on_num_tui_clicked();
	void on_num_jia_clicked();
	void on_num_jian_clicked();
	void on_num_cheng_clicked();
	void on_num_chu_clicked();
	void on_num_dian_clicked();
	void on_num_dengyu_clicked();
	void on_num_AC_clicked();



private:
	Ui::QtWidgetsApplicationClass ui;
	QString expression1;
	QString expression2;
	QStack<double> num;
	QStack<char> s;
};
