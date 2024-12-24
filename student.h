#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include "computerroom.h"
#include <string>
#include <vector>
#include <fstream>
#include "globalfile.h"
#include "orderfile.h"
class student :public identity//子类公共继承父类
{
public:
	//默认构造
	student();
	//有参构造 参数 学号 姓名 密码
	student(int id, string name, string password);
	//菜单页面
	virtual void openmenu() ;
	//申请预约
	void applyorder();
	//查看自身预约
	void showmyorder();
	//查看所有预约
	void showallorder();
	//取消预约
	void cancelorder();
	//学号需要重新封装 其他的密码以及用户名 三者通用 直接继承即可
	int my_id;
	//添加一个预约机房的记录
	vector<computerroom> vcom;
};