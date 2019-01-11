#pragma once

#include <QDialog>
#include "ui_monitorManage.h"
#include "cMonitorRsp.h"
#include<QStandardItemModel>
#include <QTableView>
#include "rspDlg.h"

class monitorManage : public QDialog, public CMonitorRsp
{
	Q_OBJECT
public:
	void InitmonitorManage();
	void InitmonitorList();
	void InitRightMenu();
	void SetTableViewAllMonitorData();
	void SetTableViewAllPlayData();
private:
	void moveCurrentItem(QTableView *source, QTableView *target);
	void WriteFile();
public slots:
	void monitorRightMoveBtnSlot();
	void monitorLeftMoveBtnSlot();
	void ActionAddSlots(bool b);
	void ActionDelSlots(bool b);
	void ActionModifSlots(bool b);
	void rspDlgManageSlots(MyEnum_RspManage type, const TAG_MONITOR& new_tag);
	void tableViewRightdownSlots_left(const QPoint &pos);
	void tableViewRightdownSlots_right(const QPoint &pos);
signals:
	void updateList_signed();
protected:
	void closeEvent(QCloseEvent *event);
private:
	vector<TAG_MONITOR> listAllMonitor;
	vector<TAG_MONITOR> listAllPlay;
	QStandardItemModel  *modelAllMonitor;
	QStandardItemModel  *modelAllPlay;
	QMenu *popMenuAdd;
	QMenu *popMenuAdd_Mod_Del;
	QAction *pActionAdd, *pActionDel, *pActionModif;
	rspDlg *prspdlg;
	QTableView *pcurSelTabView;
	TAG_MONITOR tagCuritem;
	vector<TAG_MONITOR> listData;
public:
	vector<TAG_MONITOR> listData_right;
public:
	monitorManage(QWidget *parent = Q_NULLPTR);
	~monitorManage();

private:
	Ui::monitorManage ui;
};
