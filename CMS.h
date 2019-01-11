#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CMS.h"
#include "cmsStyle.h"
#include<QPixmap>
#include <QLabel>
#include "cMonitorRsp.h"
#include "rspDlg.h"
#include "monitorManage.h"

#include <opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>
#include <QMovie>
#include <QThread>
#include<QScreen>

#pragma execution_character_set("utf-8")

class CMS : public QMainWindow, public CCmsStyle, public CMonitorRsp
{
	Q_OBJECT
public:
	virtual bool eventFilter(QObject *watched, QEvent *event);
private:
	void CmsInitStyle();
	void CmsInitAllLbl();
	void CmsSetCurLblMax();
	void CmsInitMonitorList();
	void CmsAddMonitor(const TAG_MONITOR &tag);

	void video_play(QString video, int num);
private:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void keyPressEvent(QKeyEvent *event);

	
public slots:
	void CmsUpdateMonitorList();
	void mouseDoubleClickEvent_Item(QTreeWidgetItem* item, int num);
	//void rspDlgManageSlots(MyEnum_RspManage type, const TAG_MONITOR& new_tag);
	//void showrightMenu(QPoint point);
	
private slots:
	void BtnMaxSlots();
	void BtnMinSlots();
	void BtnCloseSlots();
	void BtnFullScreenSlots();
	void pActionMonitorDrawRegionSlots(bool b);
	void BtnRspManageSlots();
private:
	QPixmap m_pixmap;
	QPoint m_pressPt;
	QLabel *monitor[12];
	QLabel *monitor_label[12];
	QTreeWidgetItem *treeWidgetRootItem;
	QMenu *pTreeMenu;
	QAction *pActionMonitorDrawRegion;
	//vector<TAG_MONITOR> listData;
	int icurSelTreeitem;
	QLabel *pcurSelLbl, *pcurSelLabText;
	bool bisMax;
	monitorManage *pmonitorManageDlg;;

	bool monitor_state[12];
	QSize monitor_size[12];
	
public:
	void imgdetect();
	CMS(QWidget *parent = Q_NULLPTR);

private:
	Ui::CMSClass ui;
};

