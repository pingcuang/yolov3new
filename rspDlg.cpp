#include "rspDlg.h"

#include <QPushButton>

rspDlg::rspDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	tag.rsp.clear();
	tag.describe.clear();
	type = MyEnum_RspManage::NON;

	connect(ui.okBtn, SIGNAL(clicked()), this, SLOT(okBtnSlots()));
	connect(ui.cancelBtn, SIGNAL(clicked()), this, SLOT(cacelBtnSlots()));
}

// iType 0���޸� 1��ɾ��
void rspDlg::SetData(MyEnum_RspManage iType, const TAG_MONITOR& param_tag)
{
	if (-1 == iType)
	{
		return;
	}
	if (MyEnum_RspManage::MODIF == iType)
	{
		type = iType;
		rspDlg::setWindowTitle(QString(u8"������-�޸� " + param_tag.describe));
	}
	else if (MyEnum_RspManage::ADD == iType)
	{
		type = iType;
		rspDlg::setWindowTitle(QString(u8"������-����"));
	}
	tag.rsp = param_tag.rsp;
	tag.describe = param_tag.describe;
	ui.rspText->setText(tag.rsp);
	ui.describeText->setText(tag.describe);
}

void rspDlg::okBtnSlots()
{
	tag.rsp = ui.rspText->text();
	tag.describe = ui.describeText->text();
	ui.rspText->setText(QString(""));
	ui.describeText->setText(QString(""));
	emit(rspDlgManageSignals(type, tag));
	close();
}

void rspDlg::cacelBtnSlots()
{
	ui.rspText->setText(QString(""));
	ui.describeText->setText(QString(""));
	close();
}

rspDlg::~rspDlg()
{
	tag.rsp.clear();
	tag.describe.clear();
	type = MyEnum_RspManage::NON;
}