#pragma once
#include<direct.h>    //头文件  
#include<iostream>  
#include<vector>
#include<opencv2/opencv.hpp>
#include<stdio.h>
#include<io.h>

void createdir(std::string dirname)
{
	int m = 0, n;
	std::string str1, str2;
	str1 = dirname;
	str2 = str1.substr(0, 2);
	str1 = str1.substr(3, str1.size());
	while (m >= 0)
	{
		m = str1.find('\\');

		str2 += '\\' + str1.substr(0, m);
		//判断该目录是否存在
		n = _access(str2.c_str(), 0);
		if (n == -1)
		{
			//创建目录文件
			_mkdir(str2.c_str());
		}
		str1 = str1.substr(m + 1, str1.size());
	}
}

long long splitpath(std::string path)
{
	std::string s = path;
	int wen = s.find('_');
	std::string sub = s.substr(wen + 1, s.length() - wen - 1);
	int cha = sub.find(".jpg");
	std::string sub1 = sub.substr(0, cha);
	std::string::iterator   it;

	for (it = sub1.begin(); it != sub1.end(); ++it)
	{
		if (*it == '.')
		{
			sub1.erase(it);
		}
	}
	//std::cout << "sub1:" << sub1 << std::endl;
	long long result;
	std::istringstream is(sub1);
	is >> result;
	return result;
}
void deleteimg(std::string folder)
{

	char *buffer;
	//也可以将buffer作为输出参数
	if ((buffer = _getcwd(NULL, 0)) == NULL)
	{
		perror("getcwd error");
	}

	std::string s(buffer);
	time_t  rawtime;
	struct tm *ptminfo;
	time(&rawtime);
	ptminfo = localtime(&rawtime);
	long long nowtime;
	std::string month = ((std::to_string(ptminfo->tm_mon + 1)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_mon + 1))) : (std::to_string(ptminfo->tm_mon + 1));
	std::string day = ((std::to_string(ptminfo->tm_mday)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_mday))) : (std::to_string(ptminfo->tm_mday));
	std::string hour = ((std::to_string(ptminfo->tm_hour)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_hour))) : (std::to_string(ptminfo->tm_hour));
	std::string min = ((std::to_string(ptminfo->tm_min)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_min))) : (std::to_string(ptminfo->tm_min));
	std::string sec = ((std::to_string(ptminfo->tm_sec)).length() == 1) ? ("0" + (std::to_string(ptminfo->tm_sec))) : (std::to_string(ptminfo->tm_sec));
	std::string abcd = std::to_string(ptminfo->tm_year + 1900) + month + day + hour + min + sec;
	std::istringstream is(abcd);
	is >> nowtime;
	//std::cout << nowtime << std::endl;
	//folder = s + "\\" + folder;
	//std::cout << "folder:" << folder << std::endl;
	std::vector<cv::String> filenames;
	cv::glob(folder, filenames);
	free(buffer);
	for (int i = 0; i < filenames.size(); i++)
	{
		long long  result = splitpath(filenames[i]);
		if (nowtime - result > 500) {
			remove((char*)filenames[i].operator std::string().c_str());
		}

		//std::cout << filenames[i] << "		jieguo："<<result<<"	nowtime:	"<<nowtime<<std::endl;
	}

}
