#pragma once
#include <QtWidgets/QMainWindow>
#include<QPushButton>

class CCmsStyle
{
public:
	CCmsStyle();
	~CCmsStyle();
public:
	void setCMSBtnStyle(QPushButton *pBtn, QString n, QString h, QString p);
	void loadQssFile(QString fileName);
};