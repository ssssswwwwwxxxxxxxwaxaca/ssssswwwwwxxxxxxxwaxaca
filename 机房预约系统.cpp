#include <iostream>
#include <string>
#include <fstream>
#include "globalfile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;
//进入教师的子菜单
void teachermenu(identity* teauser)
{
	while (true)
	{
		//调用公共的子菜单
		teauser->openmenu();
		//完成指针转换
		teacher* man = (teacher*)teauser;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//查看全部预约
			man->showallorder();
		}
		else if (select == 2)
		{
			//审核预约
			man->validorder();
		}
		else
		{
			//注销登录
			delete man;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//进入学生的子菜单
void studentmenu(identity* &stuser)
{
	while (true)
	{
		//调用学生的子菜单
		stuser->openmenu();
		//指针转换  由父指针转换为 子类指针
		student* man = (student*)stuser;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//申请预约
			man->applyorder();
		}
		else if (select == 2)
		{
			//查看自身预约
			man->showmyorder();
		}
		else if (select == 3)
		{
			//查看所有预约
			man->showallorder();
		}
		else if (select == 4)
		{
			//取消预约
			man->cancelorder();
		}
		else
		{
			//注销登录
			delete man;
			cout << "注销成功！！！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入管理员的子菜单
void managermenu(identity* &mauser)
{
	while (true)
	{
		//调用管理员的子菜单
		mauser->openmenu();
		//多态调用纯虚函数
		//把父类指针转为子类指针，调用子类其他接口
		manager* man = (manager*)mauser;
		int select;//接收用户的选择
		cin >> select;
		if (select == 1)
		{
			//添加账号

			man->addperson();
		}
		else if (select == 2)
		{
			//查看账号

			man->showperson();
		}
		else if (select == 3)
		{
			//查看机房

			man->showcomputer();
		}
		else if (select == 4)
		{
			//清空预约

			man->clearorder();
		}
		else
		{
			delete mauser;//销毁堆区的对象
			cout << "注销成功！！！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void login(string filename,int type)
{
	//父类指针 用于指向 子类对象
	identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);//in 读文件 out 写文件
	//文件不存在的情况
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	//准备用户信息
	string name;
	string password;
	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> password;
	if (type == 1)
	{
		//学生登录验证
		int fid;//从文件读取的id号
		string fname;
		string fpassword;
		while (ifs >> fid && ifs >> fname && ifs >> fpassword)
		{
			if (fid == id && fname == name && fpassword == password)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, password);
				//进入学生身份的子菜单
				studentmenu(person);
				return;
				//若在子类中使用未覆盖的纯虚函数，则无法实例化。
			}
		}

	}
	else if (type == 2)
	{
		//教师登录验证
		int Fid;//从文件读取的id号
		string Fname;
		string Fpassword;
		while (ifs >> Fid && ifs >> Fname && ifs >> Fpassword)
		{
			if (Fid == id && Fname == name && Fpassword == password)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, password);
				teachermenu(person);
				return;
				//若在子类中使用未覆盖的纯虚函数，则无法实例化。
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string Fname;
		string Fpassword;
		while ( ifs >> Fname && ifs >> Fpassword)
		{
			if (Fname == name && Fpassword == password)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new manager(name, password);//注意访问时的权限问题 管理员不需要设置编号
				//进入管理员的子菜单界面
				managermenu(person);
				return;
				//若在子类中使用未覆盖的纯虚函数，则无法实例化。
			}
		}

	}
	//其余情况 就直接失败了
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}
int main()
{
	int select;//用于接收用户的选择
	while (true)
{
		cout << "************************************" << endl;
		cout << "    欢迎使用机房预约系统     " << endl;
		cout << "请输入您的身份：" << endl;
		cout << "\t\t                        \n" << endl;
		cout << "                1.学生代表         \n" << endl;
		cout << "\t\t                        \n" << endl;
		cout << "                2.老  师         \n" << endl;
		cout << "\t\t                        \n" << endl;
		cout << "                3.管理员         \n" << endl;
		cout << "\t\t                        \n" << endl;
		cout << "                0.退  出         \n" << endl;
		cout << "请输入您的选择：" << endl;
		cin >> select;
	switch (select)
	{
		case 1:
		{
		//学生身份
			login(STUDENT_FILE, 1);
			break;
		}
		case 2:
		{
			//老师身份
			login(TEACHER_FILE, 2);
			break;
		}
		case 3:
		{
			//管理员身份
			login(ADMIN_FILE, 3);
			break;
		}
		case 0:
		{
			//退出系统
			cout << "欢迎下一次使用！！！" << endl;
			system("pause");
			exit(0);//退出系统
			break;
		}
		default:
		{
			//输入了有错误的数据
			cout << "输入有误，请重新输入！！！" << endl;
			system("pause");
			system("cls");
			//清屏并且摁任意键退出
			break;
		}
	}
}
	system("pause");
	return 0;
}