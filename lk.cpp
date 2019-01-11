#include"lk.h"

using namespace std;
using namespace cv;
//  描述：声明全局变量


lktrack::~lktrack()
{
}
// parameter: frame 输入的视频帧
//            output 有跟踪结果的视频帧
std::vector<float> lktrack::tracking(Mat &frame, Mat &output)
{
	std::vector<float> tan0h;
	float xita;
	cvtColor(frame, gray, CV_BGR2GRAY);
	frame.copyTo(output);
	// 添加特征点
	if (addNewPoints())
	{
		goodFeaturesToTrack(gray, features, maxCount, qLevel, minDist);
		points[0].insert(points[0].end(), features.begin(), features.end());
		initial.insert(initial.end(), features.begin(), features.end());
	}
	if (gray_prev.empty())
	{
		gray.copyTo(gray_prev);
	}
	// l-k光流法运动估计
	calcOpticalFlowPyrLK(gray_prev, gray, points[0], points[1], status, err);
	// 去掉一些不好的特征点
	int k = 0;
	for (size_t i = 0; i<points[1].size(); i++)
	{
		if (acceptTrackedPoint(i))
		{
			initial[k] = initial[i];
			points[1][k++] = points[1][i];
		}
	}
	points[1].resize(k);
	initial.resize(k);
	// 显示特征点和运动轨迹

	for (size_t i = 0; i<points[1].size(); i++)
	{
		line(output, initial[i], points[1][i], Scalar(0, 0, 255));
		xita = (points[1][i].y - initial[i].y)*(-1.0) / (points[1][i].x - initial[i].x);
		xita = atan(xita) * 180 / pie;
		if ((points[1][i].x - initial[i].x) < 0)
		{
			if (xita > 0)
				xita = xita - 180;
			else
				xita = xita + 180;
		}
		//cout << xita << endl;
		tan0h.push_back(xita);
		circle(output, points[1][i], 3, Scalar(0, 255, 0), -1);
	}

	// 把当前跟踪结果作为下一此参考
	swap(points[1], points[0]);
	swap(gray_prev, gray);
	return tan0h;
}

//  检测新点是否应该被添加
// return: 是否被添加标志
bool lktrack::addNewPoints()
{
	return points[0].size() <= 10;
}

//决定哪些跟踪点被接受
bool lktrack::acceptTrackedPoint(int i)
{
	return status[i] && ((abs(points[0][i].x - points[1][i].x) + abs(points[0][i].y - points[1][i].y)) > 20);
}
void  lktrack::readvideo(string rtsp)
{
	Mat frame, out;
	VideoCapture capture;
	//rtsp = "rtsp://admin:a@111.23.244.163:1554/cam/realmonitor?channel=25&subtype=1";
	capture.open(rtsp);
	if (!capture.isOpened())
	{
		//std::cout << "video not open." << std::endl;
	}
	while (true)
	{
		for (;;) {

			if (!capture.read(frame)) {
				std::cout << "No frame" << std::endl;
				capture.open(rtsp);
				break;
			}
			resize(frame, frame, Size(640, 360));
			std::vector<float> tan = tracking(frame, out);
			if (tan.size() > 2)
			{
				float f = cald(tan);
				//cout << "result:" << f << endl;
			}
			imshow("output", out);
			waitKey(1);
		}
	}
}
float lktrack::cald(std::vector<float> tan)
{

	int a[36] = { 0 };
	for (auto x : tan)
	{
		if (x == 180) x = 179; if (x == -180) x = -179;
		if (x) {
			a[int(x / 10 + 18)]++;
		}
		else
			a[int(abs(x / 10 + 17))]++;
	}
	int max = a[0];
	int i, j = 0;
	for (i = 1; i < 36; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			j = i;
		}
	}

	return (j * 10 - 180);
}
//int main()
//{
//	lktrack lk;
//	lk.readvideo("rtsp://admin:ccv123456@192.168.0.66/ch2/main/av_stream");
//}