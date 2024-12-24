#pragma once
#include <iostream>
#include "identity.h"
#include <string>、
#include "globalfile.h"
#include "orderfile.h"
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class teacher :public identity
{
public:
	//默认构造
	teacher();
	//有参构造
	teacher(int id, string name, string password);
	//菜单界面
	virtual void openmenu();
	//查看所有的预约
	void showallorder();
	//审核预约
	void validorder();
	int m_id;//多加一个教师的编号

};