#include "cMonitorRsp.h"
#include <QFile>
#include "json.h"


CMonitorRsp::CMonitorRsp()
{
}

CMonitorRsp::~CMonitorRsp()
{
}

void CMonitorRsp::writeMonitorRsp(const std::vector<TAG_MONITOR> &listData)
{
	QFile file(MONITORRSP_FILENAME);
	if (file.open(QIODevice::WriteOnly))
	{
		Json::Value data;
		for (int i = 0; i < listData.size(); i++)
		{
			Json::Value d;
			d["rsp"] = listData[i].rsp.toStdString().c_str();
			d["describe"] = listData[i].describe.toStdString().c_str();
			data["data"].append(d);
		}
		file.write(data.toStyledString().c_str());
		file.close();
	}
}

void CMonitorRsp::ReadMonitorRsp(std::vector<TAG_MONITOR> &listData)
{
	QFile file(MONITORRSP_FILENAME);
	if (file.open(QIODevice::ReadOnly))
	{
		QString content = file.readAll();
		Json::Reader reader;
		Json::Value root;

		if (reader.parse(content.toStdString(), root))
		{
			int n = root["data"].size();
			for (int i = 0; i < n; i++)
			{
				TAG_MONITOR tag;
				tag.rsp = QString::fromStdString(root["data"][i]["rsp"].asString());
				tag.describe = QString::fromStdString(root["data"][i]["describe"].asString());
				listData.push_back(tag);
			}
		}
		file.close();
	}
}