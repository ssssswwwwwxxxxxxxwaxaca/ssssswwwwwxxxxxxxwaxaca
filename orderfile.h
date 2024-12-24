#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "globalfile.h"
#include <map>
using namespace std;
class orderfile
{
public:
	//构造函数
	orderfile();
	//更新预约记录
	void updateorder();
	//记录预约条数
	int m_size;
	//记录所有预约信息的容器
	map<int, map<string, string>> m_orderdata;
};

