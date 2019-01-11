#pragma once
#include <QtWidgets/QMainWindow>
#include <QString>
#include "common.h"
#define MONITORRSP_FILENAME "monitorRsp.txt"

class  CMonitorRsp
{
public:
	void writeMonitorRsp(const std::vector<TAG_MONITOR> &listData);
	void ReadMonitorRsp(std::vector<TAG_MONITOR> &listData);
public:
	CMonitorRsp();
	~CMonitorRsp();
};

