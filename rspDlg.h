#pragma once

#include <QDialog>
#include "ui_rspDlg.h"
#include "common.h"
using namespace std;

class rspDlg : public QDialog
{
	Q_OBJECT
public:
	void SetData(MyEnum_RspManage iType, const TAG_MONITOR& tag); // iType 0ÊÇÐÞ¸Ä 1ÊÇÉ¾³ý
signals:
	void rspDlgManageSignals(MyEnum_RspManage type, const TAG_MONITOR& tag);
private slots:
	void okBtnSlots();
	void cacelBtnSlots();
private:
	TAG_MONITOR tag;
	MyEnum_RspManage type;
public:
	rspDlg(QWidget *parent = Q_NULLPTR);
	~rspDlg();

private:
	Ui::rspManage ui;

};
