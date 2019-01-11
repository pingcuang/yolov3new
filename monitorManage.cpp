#include "monitorManage.h"
#include <QMouseEvent>
#include <QMenu>
#include "rspDlg.h"

monitorManage::monitorManage(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	popMenuAdd = new QMenu(this);
	popMenuAdd_Mod_Del = new QMenu(this);

	prspdlg = new rspDlg(this);
	connect(prspdlg, SIGNAL(rspDlgManageSignals(MyEnum_RspManage, const TAG_MONITOR&)), this, SLOT(rspDlgManageSlots(MyEnum_RspManage, const TAG_MONITOR&)));

	ui.tableViewAllMonitor->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.tableViewPlayMonitor->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui.tableViewAllMonitor, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(tableViewRightdownSlots_left(QPoint)));
	connect(ui.tableViewPlayMonitor, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(tableViewRightdownSlots_right(QPoint)));
	
	pcurSelTabView = NULL;

	ui.tableViewAllMonitor->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableViewAllMonitor->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中模式为选中行
	ui.tableViewAllMonitor->setSelectionMode(QAbstractItemView::SingleSelection);//设置选中单个
	ui.tableViewPlayMonitor->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableViewPlayMonitor->setSelectionBehavior(QAbstractItemView::SelectRows);//设置选中模式为选中行
	ui.tableViewPlayMonitor->setSelectionMode(QAbstractItemView::SingleSelection);//设置选中单个
	InitRightMenu();
	InitmonitorList();
	InitmonitorManage();
}

monitorManage::~monitorManage()
{
}

void monitorManage::InitmonitorManage()
{
	connect(ui.monitorRightMoveBtn, SIGNAL(clicked()), this, SLOT(monitorRightMoveBtnSlot()));
	connect(ui.monitorLeftMoveBtn, SIGNAL(clicked()), this, SLOT(monitorLeftMoveBtnSlot()));	
}

void monitorManage::InitmonitorList()
{
	ReadMonitorRsp(listAllMonitor);

	modelAllMonitor = new QStandardItemModel();
	modelAllPlay = new QStandardItemModel();

	// 初始化
	modelAllMonitor->setColumnCount(2);
	modelAllMonitor->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("描述"));
	modelAllMonitor->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("RSP"));

	modelAllPlay->setColumnCount(2);
	modelAllPlay->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("描述"));
	modelAllPlay->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("RSP"));

	// 设置表格模型
	ui.tableViewAllMonitor->setModel(modelAllMonitor);
	ui.tableViewPlayMonitor->setModel(modelAllPlay);

	//表头信息显示居左
	ui.tableViewAllMonitor->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	ui.tableViewPlayMonitor->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	SetTableViewAllMonitorData();
	SetTableViewAllPlayData();
}

void monitorManage::InitRightMenu()
{
	pActionAdd = new QAction(this);
	pActionAdd->setText(QString(u8"添加"));
	pActionDel = new QAction(this);
	pActionDel->setText(QString(u8"删除"));
	pActionModif = new QAction(this);
	pActionModif->setText(QString(u8"修改"));

	popMenuAdd->addAction(pActionAdd);
	popMenuAdd_Mod_Del->addAction(pActionAdd);
	popMenuAdd_Mod_Del->addAction(pActionModif);
	popMenuAdd_Mod_Del->addAction(pActionDel);

	connect(pActionAdd, SIGNAL(triggered(bool)), this, SLOT(ActionAddSlots(bool)));
	connect(pActionDel, SIGNAL(triggered(bool)), this, SLOT(ActionDelSlots(bool)));
	connect(pActionModif, SIGNAL(triggered(bool)), this, SLOT(ActionModifSlots(bool)));
}

void monitorManage::SetTableViewAllMonitorData()
{
	for (int i = 0; i < listAllMonitor.size(); i++)
	{
		modelAllMonitor->setItem(i, 0, new QStandardItem((listAllMonitor[i].describe)));
		modelAllMonitor->setItem(i, 1, new QStandardItem((listAllMonitor[i].rsp)));
	}
}

void monitorManage::SetTableViewAllPlayData()
{
	for (int i = 0; i < listAllPlay.size(); i++)
	{
		modelAllPlay->setItem(i, 0, new QStandardItem((listAllPlay[i].describe)));
		modelAllPlay->setItem(i, 1, new QStandardItem((listAllPlay[i].rsp)));
	}
}

void monitorManage::monitorRightMoveBtnSlot()
{
	moveCurrentItem(ui.tableViewAllMonitor, ui.tableViewPlayMonitor);
}

void monitorManage::monitorLeftMoveBtnSlot()
{
	moveCurrentItem(ui.tableViewPlayMonitor, ui.tableViewAllMonitor);
}

void monitorManage::moveCurrentItem(QTableView *source, QTableView *target)
{
	int row = -1;
	if ((row = source->currentIndex().row()) != -1) 
	{
		QStandardItemModel *model_source = static_cast<QStandardItemModel *>(source->model());
		QVariant v_describe = model_source->data(model_source->index(row, 0));
		QVariant v_rsp = model_source->data(model_source->index(row, 1));
		model_source->removeRow(row);

		QStandardItemModel *model_target = static_cast<QStandardItemModel *>(target->model());
		model_target->setItem(model_target->rowCount(), 0, new QStandardItem(v_describe.toString()));
		model_target->setItem(model_target->rowCount()-1, 1, new QStandardItem((v_rsp.toString())));
	}

}

//bool monitorManage::eventFilter(QObject *watched, QEvent *event)
//{
//	QMouseEvent *pMouseEvent = static_cast<QMouseEvent *>(event);
//	if (pMouseEvent->button() == Qt::RightButton)
//	{
//		pcurSelTabView = qobject_cast<QTableView*>(watched);
//		if (NULL == pcurSelTabView)
//		{
//			return QObject::eventFilter(watched, event);
//		}
//
//		if (pMouseEvent->button() == Qt::RightButton)
//		{
//			if (-1 != pcurSelTabView->currentIndex().row())
//			{
//				popMenu->exec(QCursor::pos());
//			}
//		}
//	}
//
//	return QObject::eventFilter(watched, event);
//}

void monitorManage::ActionAddSlots(bool b)
{
	tagCuritem.describe.clear();
	tagCuritem.rsp.clear();
	prspdlg->SetData(MyEnum_RspManage::ADD, tagCuritem);
	prspdlg->show();
	prspdlg->exec();
}

void monitorManage::ActionDelSlots(bool b)
{
	int row = -1;
	if ((row = pcurSelTabView->currentIndex().row()) != -1)
	{
		QStandardItemModel *model_source = static_cast<QStandardItemModel *>(pcurSelTabView->model());
		model_source->removeRow(row);
	}
	WriteFile();
}

void monitorManage::ActionModifSlots(bool b)
{
	int row = -1;
	if ((row = pcurSelTabView->currentIndex().row()) != -1)
	{
		QStandardItemModel *model_source = static_cast<QStandardItemModel *>(pcurSelTabView->model());
		QVariant v_describe = model_source->data(model_source->index(row, 0));
		tagCuritem.describe = v_describe.toString();
		QVariant v_rsp = model_source->data(model_source->index(row, 1));
		tagCuritem.rsp = v_rsp.toString();

		prspdlg->SetData(MyEnum_RspManage::MODIF, tagCuritem);
		prspdlg->show();
		prspdlg->exec();
	}
}

void monitorManage::rspDlgManageSlots(MyEnum_RspManage type, const TAG_MONITOR& new_tag)
{
	QStandardItemModel *model = static_cast<QStandardItemModel *>(pcurSelTabView->model());
	if (MyEnum_RspManage::ADD == type)
	{
		model->setItem(model->rowCount(), 0, new QStandardItem(new_tag.describe));
		model->setItem(model->rowCount() - 1, 1, new QStandardItem((new_tag.rsp)));
	}
	else if (MyEnum_RspManage::MODIF == type)
	{
		int row = -1;
		if ((row = pcurSelTabView->currentIndex().row()) != -1)
		{
			model->setItem(row, 0, new QStandardItem(new_tag.describe));
			model->setItem(row, 1, new QStandardItem((new_tag.rsp)));
		}
	}
	WriteFile();
}

void monitorManage::tableViewRightdownSlots_left(const QPoint &pos)
{
	pcurSelTabView = ui.tableViewAllMonitor;
	int row = -1;
	if ((row = ui.tableViewAllMonitor->currentIndex().row()) != -1)
	{
		popMenuAdd_Mod_Del->exec(QCursor::pos());
	}
	else
	{
		popMenuAdd->exec(QCursor::pos());
	}
}

void monitorManage::tableViewRightdownSlots_right(const QPoint &pos)
{
	pcurSelTabView = ui.tableViewPlayMonitor;
	int row = -1;
	if ((row = ui.tableViewPlayMonitor->currentIndex().row()) != -1)
	{
		popMenuAdd_Mod_Del->exec(QCursor::pos());
	}
	else
	{
		popMenuAdd->exec(QCursor::pos());
	}
}

void monitorManage::WriteFile()
{
	listData.clear();

	int n = modelAllMonitor->rowCount();
	for (int i = 0; i < n; i++)
	{
		TAG_MONITOR tag;
		tag.describe = modelAllMonitor->data(modelAllMonitor->index(i, 0)).toString();
		tag.rsp = modelAllMonitor->data(modelAllMonitor->index(i, 1)).toString();
		listData.push_back(tag);
	}

	n = modelAllPlay->rowCount();
	for (int i = 0; i < n; i++)
	{
		TAG_MONITOR tag;
		tag.describe = modelAllPlay->data(modelAllPlay->index(i, 0)).toString();
		tag.rsp = modelAllPlay->data(modelAllPlay->index(i, 1)).toString();
		listData.push_back(tag);
	}
	writeMonitorRsp(listData);
}

void monitorManage::closeEvent(QCloseEvent *event)
{
	listData_right.clear();
	int n = modelAllPlay->rowCount();
	for (int i = 0; i < n; i++)
	{
		TAG_MONITOR tag;
		tag.describe = modelAllPlay->data(modelAllPlay->index(i, 0)).toString();
		tag.rsp = modelAllPlay->data(modelAllPlay->index(i, 1)).toString();
		listData_right.push_back(tag);
	}
	emit(updateList_signed());
}