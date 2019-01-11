#include "cmsStyle.h"
#include <QFile>
#include <QtWidgets/QApplication>

CCmsStyle::CCmsStyle()
{

}

CCmsStyle::~CCmsStyle()
{

}

void CCmsStyle::setCMSBtnStyle(QPushButton *pBtn, QString n, QString h, QString p)
{
	QString sheet = "QPushButton{border-image: url(" + n + ");}";
	//sheet += "QPushButton:hover{border-image: url(" + h + " );}";
	sheet += "QPushButton:pressed{border-image: url(" + p + "); }";

	pBtn->setStyleSheet(sheet);
}

void CCmsStyle::loadQssFile(QString fileName)
{
	QFile file(fileName);
	if (file.open(QIODevice::ReadOnly))
	{
		QString str = file.readAll();
		qApp->setStyleSheet(str);
		file.close();
	}
}