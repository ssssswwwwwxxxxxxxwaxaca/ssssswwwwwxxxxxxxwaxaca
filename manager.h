#pragma once
#include <iostream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerroom.h"
using namespace std;
#include "identity.h"
//管理员的类的设计
class manager :public identity
{
public:
	//默认构造
	manager();
	//有参构造
	manager(string name,string password);
	//菜单界面
	virtual void openmenu();
	//添加账号
	void addperson();
	//查看账号
	void showperson();
	//查看机房信息
	void showcomputer();
	//清空预约记录
	void clearorder();
	void initvector();
	vector<student> vstu;
	vector<teacher> vtea;
	bool checkrepeat(int id,int type);
	vector<computerroom> vcom;
};