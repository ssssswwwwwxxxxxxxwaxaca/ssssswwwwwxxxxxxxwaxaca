#pragma once//防止头文件重复包含
#include <string>
#include <iostream>
using namespace std;
//身份抽象类，封装 继承 多态
class identity
{
public:
	//操作菜单
	virtual void openmenu() = 0;//写一个纯虚函数
	//用户名
	string my_name;
	//密码
	string my_password;

};