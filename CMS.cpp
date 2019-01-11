#define _CRT_SECURE_NO_WARNINGS
#define OPENCV
#define GPU
#include "CMS.h"
#include <QPainter>
#include <QMouseEvent>
#include <QAction>
#include <QMenu>
#include <QMessageBox>
#include <QtWidgets/QApplication>
#include <stdio.h>
#include <iostream>
#include "string.h"
#include"Windows.h"
#include<time.h>
#include <sstream>
#include<thread>
#include "Wininet.h"  
//#include"yolo_v2_class.hpp"
#include<tchar.h>
#include <mutex>
#include "mkdir.h""
//#include <opencv2/opencv.hpp>
#include <ctime>
#include <vector>
#include<fstream>
#include<math.h>
#include"polylines.h"
#include "density.h"
#include"lk.h"
#include <exception>  
#define DOG
// DOG
#ifdef DOG
#include"dog/dog_api.h"
#include"dog/vendor_code.h"
#pragma comment (lib,"dog/libdog_windows_x64_3152926.lib")
#endif // DOG
#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib,"wininet.lib")
#pragma comment(lib,"yolo_cpp_dll.lib")
using namespace std;
using namespace cv;
struct img_channel
{
	Mat image;
	string   channel;
	int i;

};
struct channel_num
{
	string  channel;
	Mat frame;
	int     num;
	int i;
	bool highdense;
};

Rect danger[10];
int odd = 0;
int o = 20;
queue<img_channel> igc;
queue<channel_num> cnu;
string strResponse;
mutex mtx,mtx1;
Density dense;
condition_variable decond, encond, mecond;
bool playend = false;
QString mo;
std::vector<std::string>  obj_names, head_names;
bool select_flag = false;
Mat masks[12];
std::vector<std::vector<std::vector<cv::Point>>> contours(12);
int finish[12];//读mask完成
int a[12] = { 0 };//画区域完成
lktrack lk[12] = {};
int tracking[12] = { 0 };
string saveimgpath;
int imgbutton = 0;
string  rtsp2channel(QString rtsp)
{
	string s = rtsp.toStdString();
	int wen = s.find('?');
	if (wen == -1)
		return "none";
	string sub = s.substr(wen + 1, s.length() - wen - 1);
	int cha = sub.find("channel=");

	string sub1 = sub.substr(cha + 8, sub.length() - cha - 8);
	int jie = sub1.find('&');
	sub1 = sub1.substr(0, jie);
	return sub1;
}
void   playdecetor(QString rtsp, int i)
{
	Mat allframes[12], toframes[12];
	img_channel imgcnnel;
	if (!rtsp.isEmpty())
	{
		Mat frame;
		VideoCapture capture;
		int odd = 0;
		capture.open(rtsp.toStdString());//打开摄像头，从摄像头中获取视频
		if (!capture.isOpened())
		{
			//std::cout << "video not open." << std::endl;
		}
		while (true)
		{

			for (;;) {
				if (!capture.read(frame)) {
					//std::cout << "No frame" << std::endl;
					capture.open(rtsp.toStdString());
					continue;
				}

				if (odd == 0) {
					resize(frame, frame, Size(640, 360));
					
					/*qDebug() << "igc:" << igc.size() << endl;
					qDebug() << "o:" << o<< endl;*/
					double times; int ccc = 0;
					if (tracking[i] == 0) {
						if (ccc == 0) {
							double start = static_cast<double>(getTickCount());
							allframes[i] = frame;
							std::vector<float> tan = lk[i].tracking(allframes[i], toframes[i]);

							if (tan.size() > 2)
							{
								float f = lk[i].cald(tan);
								cv::putText(toframes[i], "degree:" + to_string(int(f)), cv::Point2f(500,20), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.7, cv::Scalar(0, 255, 0), 1);
								//cout << "result:" << f << endl;
							}
							frame = toframes[i];
							times = ((double)getTickCount() - start) / getTickFrequency();
						}ccc = ccc++ % 2;
					}
					//cv::putText(frame, to_string(int(1000 * times)) + "ms", cv::Point2f(550, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.7, cv::Scalar(0, 255, 0), 1);
					imgcnnel.image = frame;
					imgcnnel.channel = rtsp2channel(rtsp);
					imgcnnel.i = i;
					if (finish[i] == 0)
					{
						masks[i] = frame;
						finish[i] = 1;
					}
					unique_lock<mutex> lck(mtx, defer_lock);
					lck.lock();
					while (igc.size() > 2000)
						decond.wait(lck);
					igc.push(imgcnnel);
					encond.notify_all();
					lck.unlock();
				}odd = (odd + 1) % o;
			}
		}
	}
}

std::string HttpRequest(char * lpHostName, short sPort, char * lpUrl, char * lpMethod, char * lpPostData, int nPostDataLen)
{
	WCHAR iphostName[256];
	std::memset(iphostName, 0, sizeof(iphostName));
	MultiByteToWideChar(CP_ACP, 0, lpHostName, strlen(lpHostName) + 1, iphostName,
		sizeof(iphostName) / sizeof(iphostName[0]));
	WCHAR ipmethod[256];
	std::memset(ipmethod, 0, sizeof(ipmethod));
	MultiByteToWideChar(CP_ACP, 0, lpMethod, strlen(lpMethod) + 1, ipmethod,
		sizeof(ipmethod) / sizeof(ipmethod[0]));
	WCHAR ipurl[256];
	std::memset(ipurl, 0, sizeof(ipurl));
	MultiByteToWideChar(CP_ACP, 0, lpUrl, strlen(lpUrl) + 1, ipurl,
		sizeof(ipurl) / sizeof(ipurl[0]));

	HINTERNET hInternet, hConnect = NULL, hRequest = NULL;

	BOOL bRet;
	std::string strResponse;

	hInternet = (HINSTANCE)InternetOpen(L"User-Agent", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (!hInternet)
		goto Ret0;

	hConnect = (HINSTANCE)InternetConnect(hInternet, iphostName, sPort, NULL, L"HTTP/1.1", INTERNET_SERVICE_HTTP, 0, 0);
	if (!hConnect)
		goto Ret0;

	hRequest = (HINSTANCE)HttpOpenRequest(hConnect, ipmethod, ipurl, L"HTTP/1.1", NULL, NULL, INTERNET_FLAG_RELOAD, 0);
	if (!hRequest)
		goto Ret0;

	//bRet = HttpAddRequestHeaders(hRequest,"Content-Type: application/x-www-form-urlencoded",Len(FORMHEADERS),HTTP_ADDREQ_FLAG_REPLACE | HTTP_ADDREQ_FLAG_ADD);  
	//if(!bRet)  
	//goto Ret0;  

	bRet = HttpSendRequest(hRequest, NULL, 0, lpPostData, nPostDataLen);
	while (TRUE)
	{
		char cReadBuffer[4096];
		unsigned long lNumberOfBytesRead;
		bRet = InternetReadFile(hRequest, cReadBuffer, sizeof(cReadBuffer) - 1, &lNumberOfBytesRead);
		if (!bRet || !lNumberOfBytesRead)
			break;
		cReadBuffer[lNumberOfBytesRead] = 0;
		strResponse = strResponse + cReadBuffer;
	}

Ret0:
	if (hRequest)
		InternetCloseHandle(hRequest);
	if (hConnect)
		InternetCloseHandle(hConnect);
	if (hInternet)
		InternetCloseHandle(hInternet);

	return strResponse;
}
bool askhttp(string str_url, string parkcode, string channelcode, int num, bool debug)
{
	if (str_url.size() <7)
		return false;
	//分解url
	string sub1 = str_url.substr(7, str_url.length() - 7);
	int l = sub1.find(':');
	if (l<0)
		return false;
	string str_ip = sub1.substr(0, l);
	int l2 = sub1.find('/');
	if (l2<0)
		return false;
	string str_port = sub1.substr(l + 1, l2 - l - 1);
	string url = sub1.substr(l2, sub1.length() - l2);

	/*char a[10];
	sprintf_s(a, "%d", status);
	string status_t = a;*/
#ifdef _WIN32
	short uport = atoi(str_port.c_str());

	string sendData = url + "?" + "parkcode=" + parkcode + "&" + "channelcode=" + channelcode + "&" + "num=" + to_string(num);
	strResponse = HttpRequest(const_cast<char *>(str_ip.c_str()), uport, const_cast<char *>(sendData.c_str()), "GET", NULL, 0);

	return true;
#else
	/*
	string sub1 = str_url.substr(7, str_url.length() - 7);
	int l = sub1.find(':');
	if (l<0)
	return false;
	string str_ip = sub1.substr(0, l);
	int l2 = sub1.find('/');
	if (l2<0)
	return false;
	string str_port = sub1.substr(l + 1, l2 - l - 1);
	string url = sub1.substr(l2, sub1.length() - l2);
	*/
	int sockfd, ret, i, h;
	struct sockaddr_in servaddr;
	char str1[4096], str2[4096], buf[4096], *str;
	socklen_t len;
	fd_set t_set1;
	struct timeval tv;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("创建网络连接失败,本线程即将终止---socket error!\n");
		return false;
	};

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	int port_i = atoi(str_port.c_str());
	servaddr.sin_port = htons(port_i);
	if (inet_pton(AF_INET, str_ip.c_str(), &servaddr.sin_addr) <= 0) {
		printf("创建网络连接失败,本线程即将终止--inet_pton error!\n");
		return false;
	};

	if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
		printf("连接到服务器失败,connect error!\n");
		return false;
	}
	if (debug) {
		printf("与远端建立了连接\n");
	}
	char tem_c[128];
	string str_tem = "POST " + url + "?code=" + code + "&jobcode=" + jobcode + other;
	sprintf(tem_c, "&status=%d HTTP/1.1\n", status);
	str_tem += tem_c;
	memset(str1, 0, 4096);
	strcat(str1, str_tem.c_str());
	strcat(str1, "Host: www.webxml.com.cn\n");
	strcat(str1, "Content-Type: application/x-www-form-urlencoded\n");
	strcat(str1, "Content-Length: ");
	//发送数据
	memset(str2, 0, 4096);
	strcat(str2, "qqCode=474497857");
	len = strlen(str2);
	sprintf(tem_c, "%d", len);
	strcat(str1, tem_c);
	strcat(str1, "\n\n");
	strcat(str1, str2);
	strcat(str1, "\r\n\r\n");

	if (debug) {
		printf("%s\n", str1);
	}

	ret = write(sockfd, str1, strlen(str1));
	if (ret < 0) {
		printf("发送失败！错误代码是%d，错误信息是'%s'\n", errno, strerror(errno));
		return false;
	}
	else {
		if (debug) {
			printf("消息发送成功，共发送了%d个字节！\n\n", ret);
		}
	}

	FD_ZERO(&t_set1);
	FD_SET(sockfd, &t_set1);

	sleep(2);
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	h = select(sockfd + 1, &t_set1, NULL, NULL, &tv);
	if (h < 0) {
		close(sockfd);
		printf("在读取数据报文时SELECT检测到异常，该异常导致线程终止！\n");
		return false;
	};

	if (h > 0) {
		memset(buf, 0, 4096);
		i = read(sockfd, buf, 4095);
		if (i == 0) {
			close(sockfd);
			printf("读取数据报文时发现远端关闭，该线程终止！\n");
			return  false;
		}
		if (debug) {
			printf("读取数据  len:%d\n", i);
			printf("%s\n", buf);
		}
	}
	close(sockfd);
	return true;
#endif
}
int  draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names, int ii)
{
	int cols = mat_img.cols;
	int rows = mat_img.rows;
	drawContours(mat_img, contours.at(ii), 0, cv::Scalar(0,255,0), 2);
	int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };
	int hdcount = 0;
	int areanum = 0;
	for (auto &i : result_vec) {

		if (obj_names.size() > i.obj_id) {
			std::string obj_name = obj_names[i.obj_id];
			if (obj_name == "head" || obj_name == "person")
			{
				/*if (i.w * i.h > 10000)
				{
					continue;
				}*/
				//hdcount += int(10000.0*sqrt(i.w*i.h) / 20.0 / pow((i.y + 0.5*i.h), 2));
				hdcount++;
				/*}
				{	*/
				//if (obj_name == "person")

				cv::Scalar color = obj_id_to_color(i.obj_id);
				cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 1);
				int foot = i.y + i.h; int left = i.x; int right = i.x + i.w;
				Point foot1 = Point(left, foot); Point foot2 = Point(right, foot);

				//contours = py0.contour;

				if (a[ii] && contours.at(ii).size()>0)
				{

					if (pointPolygonTest(contours.at(ii)[0], foot1, false) == 1 && pointPolygonTest(contours.at(ii)[0], foot2, false) == 1 && obj_name == "person") {
						cv::putText(mat_img, "danger!", cv::Point2f(10, 100), cv::FONT_HERSHEY_COMPLEX_SMALL, 2, cv::Scalar(0, 0, 255), 2);
						areanum++;
					}
				}
				if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
				cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
				int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
				/*cv::rectangle(mat_img, cv::Point2f(max((int)i.x - 1, 0), max((int)i.y - 30, 0)),
				cv::Point2f(min((int)i.x + max_width, mat_img.cols - 1), min((int)i.y, mat_img.rows - 1)),
				color, CV_FILLED, 8, 0);*/
				cv::putText(mat_img, obj_name, cv::Point2f(i.x, i.y), cv::FONT_HERSHEY_COMPLEX_SMALL, 0.5, color, 1);
			}
		}
	}
	stringstream stream, stream1;
	stream << hdcount;
	string temp = stream.str();
	stream1 << areanum;
	string area = stream1.str();
	string count = "nums:" + temp + "      areanum:" + area;
	cv::putText(mat_img, count, cv::Point2f(cols / 25, rows / 20), cv::FONT_HERSHEY_COMPLEX_SMALL, cols/600, cv::Scalar(255, 0, 255), cols/600);
	return hdcount;

}
std::vector<std::string> objects_names_from_file(std::string const filename) {
	std::ifstream file(filename);
	std::vector<std::string> file_lines;
	if (!file.is_open()) return file_lines;
	for (std::string line; getline(file, line);) file_lines.push_back(line);
	std::cout << "object names loaded \n";
	return file_lines;
}
void CMS::imgdetect()
{
	
		Detector detector("yolov3.cfg", "yolov3.weights");
		Detector dethead("head.cfg", "head_45344.weights");

	while (true)
	{
		unique_lock<mutex> lck1(mtx, defer_lock);
		lck1.lock();
		while (igc.empty())  encond.wait(lck1);
		img_channel imgc = igc.front();
		igc.pop();
		decond.notify_all();
		lck1.unlock();
		Mat frame = imgc.image;
		string channel = imgc.channel;
		int i = imgc.i;
		std::vector<bbox_t> result_vec = dethead.detect(frame, 0.15);
		int num = 0;
		if (dense.judgedense(frame, result_vec, obj_names))
		{
			cv::putText(frame, "highdense", cv::Point2f(frame.cols/1.8, frame.rows / 20), cv::FONT_HERSHEY_COMPLEX_SMALL, frame.cols / 600, cv::Scalar(0, 255, 0), frame.cols / 600);
			num = draw_boxes(frame, result_vec, head_names, i);
		}
		else
		{
			result_vec.clear();
			result_vec = detector.detect(frame, 0.15);
			cv::putText(frame, "lowdense", cv::Point2f(frame.cols / 1.8, frame.rows / 20), cv::FONT_HERSHEY_COMPLEX_SMALL, frame.cols / 600, cv::Scalar(0, 255, 0), frame.cols / 600);
			num = draw_boxes(frame, result_vec, obj_names, i);
		}
		QImage image = QImage((const uchar*)frame.data,
			frame.cols, frame.rows,
			QImage::Format_RGB888).rgbSwapped();
		image = image.scaled(monitor_size[i], Qt::IgnoreAspectRatio);
		monitor[i]->setPixmap(QPixmap::fromImage(image));
		channel_num cn;
		cn.channel = channel;
		cn.num = num;
		cn.i = i;
		//cn.frame = frame;
		unique_lock<mutex> lck2(mtx1, defer_lock);
		lck2.lock();
		cnu.push(cn);
		lck2.unlock();
		//qDebug() << "cnu:" << cnu.size() << endl;

		time_t rawtime;
		struct tm *ptminfo;
		time(&rawtime);
		ptminfo = localtime(&rawtime);
		string month = ((std::to_string(ptminfo->tm_mon + 1)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_mon + 1))) : (std::to_string(ptminfo->tm_mon + 1));
		string day = ((std::to_string(ptminfo->tm_mday)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_mday))) : (std::to_string(ptminfo->tm_mday));
		string hour = ((std::to_string(ptminfo->tm_hour)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_hour))) : (std::to_string(ptminfo->tm_hour));
		string min = ((std::to_string(ptminfo->tm_min)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_min))) : (std::to_string(ptminfo->tm_min));
		string sec = ((std::to_string(ptminfo->tm_sec)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_sec))) : (std::to_string(ptminfo->tm_sec));
		std::string abcd = std::to_string(ptminfo->tm_year + 1900) + "." + month + "." + day + "." + hour + "." + min + "." + sec;
		cv::String savepath = saveimgpath + "/" + std::to_string(i) + "/" + std::to_string(i) + "_" + abcd + ".jpg";
		//保存图片到本地供网页调用
		try {
			if (!frame.empty())
			{
				createdir(saveimgpath);
				createdir(saveimgpath + "/" + std::to_string(i));
				deleteimg(saveimgpath + "/" + std::to_string(i));
				imwrite(savepath, frame);
			}
		}
		catch (exception& e)
		{
			string str = "invalid img save path";
			int ret1 = QMessageBox::question(this, tr("invalid img save path"), QString::fromStdString(str), QMessageBox::Yes);
			if (ret1 == QMessageBox::Yes)
				exit(0);
		}

		//qDebug() << danger[i].x<< danger[i].x << danger[i].width << danger[i].height<< endl;
		/*imshow(im, frame);
		cvWaitKey(1);*/
		
		//switch (i)
		//{
		//case 0:ui.video0->setPixmap(QPixmap::fromImage(image)); break;
		//case 1:ui.video1->setPixmap(QPixmap::fromImage(image)); break;
		//case 2:ui.video2->setPixmap(QPixmap::fromImage(image)); break;
		//case 3:ui.video3->setPixmap(QPixmap::fromImage(image)); break;
		//case 4:ui.video4->setPixmap(QPixmap::fromImage(image)); break;
		//case 5:ui.video5->setPixmap(QPixmap::fromImage(image)); break;
		//case 6:ui.video6->setPixmap(QPixmap::fromImage(image)); break;
		//case 7:ui.video7->setPixmap(QPixmap::fromImage(image)); break;
		//case 8:ui.video8->setPixmap(QPixmap::fromImage(image)); break;
		//case 9:ui.video9->setPixmap(QPixmap::fromImage(image)); break;
		//default:break;
		//}

		

	}
}
CMS::CMS(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
#ifdef DOG

	std::thread Tdog([&]()
	{
		while (true)
		{
			Sleep(1000);
			int flag_dog = 0;
			std::string str_dog;

			dog_status_t   status;
			dog_handle_t   handle;
			status = dog_login(1, (dog_vendor_code_t *)vendorCode, &handle);
			switch (status)
			{
			case DOG_STATUS_OK:
				flag_dog = 1;
				str_dog = "OK";
				break;

			case DOG_FEATURE_NOT_FOUND:
				str_dog = "login to default feature failed";
				break;

			case DOG_NOT_FOUND:
				str_dog = "no SuperDog with vendor code 3152926 found";
				break;

			case DOG_INV_VCODE:
				str_dog = "invalid vendor code";
				break;

			case DOG_LOCAL_COMM_ERR:
				printf("communication error between API and local SuperDog License Manager\n");
				break;

			default:
				char a_tem[50];
				sprintf_s(a_tem, "login to default feature failed with status %d", status);
				str_dog = a_tem;
			}
			if (status) {
				dog_logout(handle);
			}
			if (flag_dog == 0) {
				int ret1 = QMessageBox::question(this, tr("message"), QString::fromStdString(str_dog), QMessageBox::Yes);
				if (ret1 == QMessageBox::Yes)
					exit(0);
			}
		}
	});
	Tdog.detach();
#endif  
	std::string  names_file = "coco.names";
	std::string  names_head = "head.names";
	/*std::string cfg_file = "yolov3.cfg";
	std::string  weights_file = "yolov3.weights";*/
	obj_names = objects_names_from_file(names_file);//获得分类对象名称
	head_names = objects_names_from_file(names_head);
	ifstream save("savepath.txt");
	getline(save, saveimgpath);
	treeWidgetRootItem = NULL;
	pTreeMenu = NULL;
	pmonitorManageDlg = new monitorManage();

	connect(ui.minBtn, SIGNAL(clicked()), this, SLOT(BtnMinSlots()));
	connect(ui.maxBtn, SIGNAL(clicked()), this, SLOT(BtnMaxSlots()));
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(BtnCloseSlots()));
	connect(ui.fullScreenBtn, SIGNAL(clicked()), this, SLOT(BtnFullScreenSlots()));
	connect(ui.rspManageBtn, SIGNAL(clicked()), this, SLOT(BtnRspManageSlots()));

	connect(pmonitorManageDlg, SIGNAL(updateList_signed()), this, SLOT(CmsUpdateMonitorList()));

	monitor[0] = ui.monitor1;
	monitor[0]->installEventFilter(this);
	monitor[1] = ui.monitor2;
	monitor[1]->installEventFilter(this);
	monitor[2] = ui.monitor3;
	monitor[2]->installEventFilter(this);
	monitor[3] = ui.monitor4;
	monitor[3]->installEventFilter(this);
	monitor[4] = ui.monitor5;
	monitor[4]->installEventFilter(this);
	monitor[5] = ui.monitor6;
	monitor[5]->installEventFilter(this);
	monitor[6] = ui.monitor7;
	monitor[6]->installEventFilter(this);
	monitor[7] = ui.monitor8;
	monitor[7]->installEventFilter(this);
	monitor[8] = ui.monitor9;
	monitor[8]->installEventFilter(this);
	monitor[9] = ui.monitor10;
	monitor[9]->installEventFilter(this);
	monitor[10] = ui.monitor11;
	monitor[10]->installEventFilter(this);
	monitor[11] = ui.monitor12;
	monitor[11]->installEventFilter(this);

	monitor_label[0] = ui.monitor_label_1;
	monitor_label[1] = ui.monitor_label_2;
	monitor_label[2] = ui.monitor_label_3;
	monitor_label[3] = ui.monitor_label_4;
	monitor_label[4] = ui.monitor_label_5;
	monitor_label[5] = ui.monitor_label_6;
	monitor_label[6] = ui.monitor_label_7;
	monitor_label[7] = ui.monitor_label_8;
	monitor_label[8] = ui.monitor_label_9;
	monitor_label[9] = ui.monitor_label_10;
	monitor_label[10] = ui.monitor_label_11;
	monitor_label[11] = ui.monitor_label_12;

	pActionMonitorDrawRegion = new QAction(ui.widget_4);
	pActionMonitorDrawRegion->setText(QString("画区域"));

	ui.treeWidget->setHeaderHidden(true);
	ui.treeWidget->setHeaderLabels(QStringList()
		<< u8"描述"
		<< u8"rsp");

	//隐藏视频id项
	ui.treeWidget->header()->hideSection(1);
	ui.treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);//右键 不可少否则右键无反应
	connect(ui.treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showrightMenu(QPoint)));


	connect(pActionMonitorDrawRegion, SIGNAL(triggered(bool)), this, SLOT(pActionMonitorDrawRegionSlots(bool)));
	icurSelTreeitem = -1;
	pcurSelLbl = NULL;
	pcurSelLabText = NULL;
	bisMax = false;
	CmsInitStyle();
	CmsInitMonitorList();
	CmsInitAllLbl();

	connect(ui.treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(mouseDoubleClickEvent_Item(QTreeWidgetItem*, int)));
	for (int i = 0; i < 12; i++)
	{
		monitor_state[i] = false;
		monitor[i]->installEventFilter(this);
		monitor_size[i].setWidth(224);
		monitor_size[i].setHeight(126);
	}
	std::thread t2([&]() {imgdetect(); });
	t2.detach();
	std::thread t81([&]()
	{
		while (true)
		{
			//Sleep(5000);
			if (cnu.empty())
			{
				continue;
			}
			unique_lock<mutex> lck2(mtx1, defer_lock);
			lck2.lock();
		
			channel_num cn;
			cn = cnu.front();
			cnu.pop();
			lck2.unlock();
			string channel = cn.channel;
			int nums = cn.num;
			int i = cn.i;
			//Mat frame = cn.frame;
			/*QImage image = QImage((const uchar*)frame.data,
				frame.cols, frame.rows,
				QImage::Format_RGB888).rgbSwapped();
			image = image.scaled(monitor_size[i], Qt::IgnoreAspectRatio);
			monitor[i]->setPixmap(QPixmap::fromImage(image));*/
			askhttp("http://139.196.193.132:8999/ZhManageWebApi/receiveJkNum", "001", std::to_string(i), nums, false);
			//qDebug() << QString::fromStdString(strResponse) << endl;
			/*std::queue<channel_num> empty;
			std::swap(cnu, empty);*/
		}
	});
	t81.detach();
	
}

void CMS::CmsInitStyle()
{
	setWindowFlag(Qt::FramelessWindowHint);

	setCMSBtnStyle(ui.minBtn, ":/CMS/img/icon_small.png", ":/CMS/img/icon_smallh.png", ":/CMS/img/icon_smallz.png");
	setCMSBtnStyle(ui.maxBtn, ":/CMS/img/icon_down.png", ":/CMS/img/icon_downh.png", ":/CMS/img/icon_downz.png");
	setCMSBtnStyle(ui.closeBtn, ":/CMS/img/icon_close.png", ":/CMS/img/icon_closeh.png", ":/CMS/img/icon_closez.png");
	setCMSBtnStyle(ui.fullScreenBtn, ":/CMS/img/icon_max.png", ":/CMS/img/icon_max.png", ":/CMS/img/icon_maxh.png");
	setCMSBtnStyle(ui.rspManageBtn, ":/CMS/img/setting.png", ":/CMS/img/setting.png", ":/CMS/img/setting.png");

	setStyleSheet("background-color:#333333;");
	
	loadQssFile(":/CMS/qss/CMSqss.css");

}

void CMS::CmsInitAllLbl()
{
	for (int i = 0; i < 12; i++)
	{
		monitor[i]->setStyleSheet("background-color: #000000");
		monitor[i]->setFrameShape(QFrame::Box);
	}
}

//双击最大化
void CMS::CmsSetCurLblMax()
{
	for (int i = 0; i < 12; i++)
	{
		monitor[i]->setVisible(false);
		monitor_label[i]->setVisible(false);
	}
	if (bisMax)
	{
		for (int i = 0; i < 12; i++)
		{
			monitor[i]->setVisible(true);
			monitor_label[i]->setVisible(true);
			monitor[i]->setMaximumSize(ui.widget_4->width() / 4-3, ui.widget_4->height() / 3);
			monitor_size[i] = monitor[i]->size();
		}
		
		bisMax = false;
	}
	else
	{
		pcurSelLbl->setVisible(true);
		pcurSelLbl->setMaximumSize(ui.widget_4->width(), ui.widget_4->height());
		for (int i = 0; i < 12; i++)
		{
			if (monitor[i] == pcurSelLbl)
			{
				monitor_size[i] = ui.widget_4->size();
			}			
		}
		
		bisMax = true;
	}
	
}

void CMS::CmsInitMonitorList()
{
	ui.treeWidget->clear();
	treeWidgetRootItem = new QTreeWidgetItem(ui.treeWidget);
	treeWidgetRootItem->setText(0, QString("监控列表"));
	treeWidgetRootItem->setIcon(0, QIcon(":/CMS/img/icon_monitorListParent.png"));
}

void CMS::CmsAddMonitor(const TAG_MONITOR &tag)
{
	QTreeWidgetItem *subItem = new QTreeWidgetItem(treeWidgetRootItem);
	subItem->setText(0, tag.describe);
	subItem->setText(1, tag.rsp);
	subItem->setIcon(0, QIcon(":/CMS/img/icon_monitorListSub.png"));
	treeWidgetRootItem->addChild(subItem);
	ui.treeWidget->expandAll();
}

void CMS::CmsUpdateMonitorList()
{
	QTreeWidgetItemIterator it(treeWidgetRootItem);
	while (*it) {
		//do something like
		treeWidgetRootItem->removeChild(*it);
		it++;
	}
	for (vector<TAG_MONITOR>::iterator it = pmonitorManageDlg->listData_right.begin(); it != pmonitorManageDlg->listData_right.end(); it++)
	{
		QTreeWidgetItem *subItem = new QTreeWidgetItem(treeWidgetRootItem);
		subItem->setText(0, it->describe);
		subItem->setText(1, it->rsp);
		subItem->setIcon(0, QIcon(":/CMS/img/icon_monitorListSub.png"));
		treeWidgetRootItem->addChild(subItem);
	}
	ui.treeWidget->expandAll();
}

void CMS::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, this->width(), this->height(), m_pixmap);
}

void CMS::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_pressPt = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
}

void CMS::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() == Qt::LeftButton)
	{
		move(event->globalPos() - m_pressPt);
		event->accept();
	}
}

void CMS::BtnMaxSlots()
{
	
	if (isMaximized())
	{		
		CMS::showNormal();	
		if (bisMax)
		{
			for (int i = 0; i < 12; i++)
			{
				if (monitor[i] == pcurSelLbl)
				{
					monitor_size[i] = ui.widget_4->size();
				}
			}
		}
	}
	else
	{
		CMS::setWindowState(Qt::WindowMaximized);	//放大	
		if (bisMax)
		{
			for (int i = 0; i < 12; i++)
			{
				if (monitor[i] == pcurSelLbl)
				{
					monitor_size[i] = ui.widget_4->size();
				}
			}
		}
	}
	
}
//最小化
void CMS::BtnMinSlots()
{
	CMS::showMinimized();
}

//关闭
void CMS::BtnCloseSlots()
{
	string str = "Are you sure to quit this application?";
	int ret1 = QMessageBox::question(this, tr("close"), QString::fromStdString(str), QMessageBox::Yes | QMessageBox::No);
	if (ret1 == QMessageBox::Yes)
		exit(0);
}

//全屏显示
void CMS::BtnFullScreenSlots()
{
	ui.widget->setVisible(false);
	ui.widget_3->setVisible(false);
	ui.widget_5->setVisible(false);	
	CMS::showFullScreen();
	if (!bisMax)
	{
		for (int i = 0; i < 12; i++)
		{
			monitor[i]->setMaximumSize(ui.widget_4->width() / 4-3, ui.widget_4->height() / 3);
			monitor_size[i] = monitor[i]->size();
		}
	}
	else
	{
		pcurSelLbl->setMaximumSize(ui.widget_4->width(), ui.widget_4->height());
		for (int i = 0; i < 12; i++)
		{
			if (monitor[i] == pcurSelLbl)
			{
				monitor_size[i] = ui.widget_4->size();
			}
		}
	}
	
}

//void CMS::rspDlgManageSlots(MyEnum_RspManage type, const TAG_MONITOR& new_tag)
//{
//	if (MyEnum_RspManage::ADD == type)
//	{
//		CmsAddMonitor(new_tag);
//	}
//	else if (MyEnum_RspManage::MODIF == type)
//	{
//		QTreeWidgetItem *itemSub = treeWidgetRootItem->child(icurSelTreeitem);
//		itemSub->setText(0, new_tag.describe);
//		itemSub->setText(1, new_tag.rsp);
//		itemSub->setIcon(0, QIcon(":/CMS/img/icon_monitorListSub.png"));
//		listData[icurSelTreeitem].describe = new_tag.describe;
//		listData[icurSelTreeitem].rsp = new_tag.rsp;
//		writeMonitorRsp(listData);
//	}
//}

//void CMS::showrightMenu(QPoint point)
//{
//	QTreeWidgetItem *item = ui.treeWidget->itemAt(point); //可得到右键条目
//	QMenu *popMenu = new QMenu(ui.treeWidget);
//	if (item == NULL)
//	{
//		//这种情况是右键的位置不在treeItem的范围内，即在空白位置右击
//		tagCurTreeitem.describe.clear();
//		tagCurTreeitem.rsp.clear();
//		popMenu->addAction(pActionAdd);
//	}
//	else
//	{
//		QTreeWidgetItem* parent = item->parent();
//		if (NULL == parent) // 在父节点上不弹出任何菜单
//		{
//			return;
//		}
//		//定义一个右键弹出菜单
//		int index = 0;
//		for (vector<TAG_MONITOR>::iterator it = listData.begin(); it != listData.end(); it++, index++)
//		{
//			if (item->text(0) == it->describe)
//			{
//				icurSelTreeitem = index;
//				break;
//			}
//		}
//		tagCurTreeitem.describe = item->text(0);
//		tagCurTreeitem.rsp = item->text(1);
//		popMenu->addAction(pActionModif);//往菜单内添加QAction   该action在前面用设计器定义了
//		popMenu->addAction(pActionDel);
//	}
//	popMenu->exec(QCursor::pos());
//}


bool CMS::eventFilter(QObject *watched, QEvent *event)
{
	for (int j = 0; j< 12; j++)
	{
		if (watched == monitor[j])
		{
			if (event->type() == QEvent::Resize)
			{
				if (!bisMax)
				{
					for (int i = 0; i < 12; i++)
					{
						monitor[i]->setMaximumSize(ui.widget_4->width() / 4 - 3, ui.widget_4->height() / 4);
						monitor_size[i] = monitor[i]->size();
					}
				}				
				
			}
		}
	}


	QMouseEvent *pMouseEvent = static_cast<QMouseEvent *>(event);
	if ((event->type() == QEvent::MouseButtonDblClick) && pMouseEvent->button() == Qt::LeftButton)
	{
		CmsSetCurLblMax();
	}
	if (event->type() == QEvent::MouseButtonPress)
	{
		pcurSelLbl = qobject_cast<QLabel*>(watched);
		if (NULL == pcurSelLbl)
		{
			return QObject::eventFilter(watched, event);
		}
		CmsInitAllLbl();
		pcurSelLbl->setFocus();
		pcurSelLbl->setStyleSheet("border-width: 1px;border-style: solid;border-color: rgb(255, 170, 0);");

		if (pMouseEvent->button() == Qt::RightButton)
		{
			
			QMenu *popMenu = new QMenu(this);
			popMenu->addAction(pActionMonitorDrawRegion);//往菜单内添加QAction   该action在前面用设计器定义了
			popMenu->exec(QCursor::pos());
		}
	}

	

	return QObject::eventFilter(watched, event);
}


//窗口最大化
void CMS::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Escape:
		ui.widget->setVisible(true);
		ui.widget_3->setVisible(true);
		ui.widget_5->setVisible(true);
		CMS::setWindowState(Qt::WindowMaximized);
			break;
	default:
		keyPressEvent(event);
		break;
	}
}

void CMS::pActionMonitorDrawRegionSlots(bool b)
{
	int i;
	for ( i = 0; i < 12; i++)
	{
		if (monitor[i] == pcurSelLbl)
		{
			break;
		}
	}
	//QMessageBox::information(NULL, "Title", "画区域", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	a[i] = 1;
	Pyline py0(masks[i]);
	py0.drawpoly("iframes"+to_string(i));
	contours.at(i).assign(py0.contour.begin(), py0.contour.end());
}

void CMS::BtnRspManageSlots()
{
	pmonitorManageDlg->exec();
}

void CMS::mouseDoubleClickEvent_Item(QTreeWidgetItem* item, int num)
{
	int j; std::thread t[12];
	for (j = 0; j < 12; j++)
	{
		if (monitor_state[j] && monitor_label[j]->text() == item->text(0))//当前点击的item 正在播放视频break;
		{
			monitor_label[j]->setText("");
			monitor_state[j] = false;				//视屏线程停止用此变量，j为video_play(QString video,int num)中的num

			break;
		}
	}
	
			if (j == 12)
			{
				for (j = 0; j < 12; j++)
				{  //判断label是否播放视频
					if (monitor_state[j] == false)
					{
						monitor_label[j]->setText(item->text(0));
						monitor_state[j] = true;
						break;
					}
				}
				if (j != 12)
				{
					//video_play(item->text(1), j);
					t[j]=std:: thread ([&]() { playdecetor(item->text(1), j); });
					t[j].detach();
				}
			}
		
}

