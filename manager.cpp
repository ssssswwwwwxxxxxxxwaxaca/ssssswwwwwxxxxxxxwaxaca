#include "manager.h"
#include <fstream>
#include "globalfile.h"
#include <iomanip>
//默认构造
manager::manager()
{

}
//有参构造
manager::manager(string name, string password)
{
	//管理员类中不添加 编号 仅需要用户名和密码完成就行
	this->my_name = name;
	this->my_password = password;
	this->initvector();
	//有参构造的同时完成初始化容器
	//初始化机房信息 利用容器读取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);//从文件中往外读写数据
	computerroom com;
	while (ifs >> com.c_id && ifs >> com.max_size)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << vcom.size() << endl;
}
//菜单界面
void manager::openmenu()
{
	cout << "欢迎管理员" << this->my_name << "登录！" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      1.添加账号\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      2.查看账号\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      3.查看机房\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      4.清空预约\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      0.注销登录\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "请选择您的操作：" << endl;
 }
//添加账号
void manager::addperson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
	string filename;
	string tip;
	string errortip;
	ofstream ofs;//对文件进行写入
	int select;
	cin >> select;
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学生的学号发生重复，请重新输入";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入职工编号：";
		errortip = "教师的职工号发生重复，请重新输入";
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string mypassword;
	while (1)
	{
		cout << tip << endl;//对外输出提示语
		cin >> id;
		bool ret = checkrepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> mypassword;
	ofs << id << " " << name << " " << mypassword << endl;//把数据写入到文件中
	cout << "添加成功！！！" << endl;
	this->initvector();//文件发生更新 及时更新系统库
	system("pause");
	system("cls");
	ofs.close();
}
//查看账号
void manager::showperson()
{
	cout << "选择查看内容：" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select=0;
	cin >> select;
	if (select == 1)
	{
		//查看所有的学生
		cout << left;
		cout <<setw(10) <<"学号" << setw(10) << "用户名" << setw(10) << "密码" << endl;
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			cout << setw(10) << (*it).my_id << setw(10) << (*it).my_name << setw(10) << (*it).my_password << endl;
		}
		cout << "-------------------------------------------------------------------------" << endl;
	}
	else
	{
		//查看老师
		cout << left;
		cout << setw(10)<<"职工号" << setw(10) << "用户名" << setw(10) << "密码" << endl;
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			cout << (*it).m_id << setw(10) << (*it).my_name << setw(10) << (*it).my_password << endl;
		}
		cout << "------------------------------------------------------------------------" << endl;
	}
}
//查看机房信息
void manager::showcomputer()
{
	cout << "机房的信息如下：" << endl;
	for (vector<computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "机房编号：" << (*it).c_id << "     " << "机房容量" << (*it).max_size << endl;
	}
	system("pause");
	system("cls");

}
//清空预约记录
void manager::clearorder()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}
void manager::initvector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	student s;
	while (ifs >> s.my_id && ifs >> s.my_name && ifs >> s.my_password)
	{
		vstu.push_back(s);
	}
	cout << "当前学生的数量为：" << vstu.size() << endl;
	ifs.close();//学生初始化完成 关闭文件

	//读取老师的文件信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败！" << endl;
	}
	teacher t;
	while (ifs >> t.m_id && ifs >> t.my_name && ifs >> t.my_password)
	{
		vtea.push_back(t);
	}
	cout << "当前教师的数量为：" << vtea.size() << endl;
	ifs.close();
}
bool manager::checkrepeat(int id,int type)
{
	if (type == 1)
	{
		//在学生里面完成检测
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (id == (*it).my_id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<teacher>::iterator is = vtea.begin(); is != vtea.end(); is++)
		{
			if (id == (*is).m_id)
			{
				return true;
			}
		}
	}
	return false;
}