#include "student.h"
//默认构造
student::student()
{

}
//有参构造 参数 学号 姓名 密码
student::student(int id, string name, string password)
{
	this->my_id=id;
	this->my_name = name;
	this->my_password = password;
	//读取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);//读取文件
	computerroom c;
	while (ifs >> c.c_id && ifs >> c.max_size)
	{
		this->vcom.push_back(c);
	}
	ifs.close();
}
//菜单界面
void student::openmenu()
{
	cout << "欢迎学生" << this->my_name << "登录！" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      1.申请预约\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      2.查看我的预约\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      3.查看所有预约\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      4.取消预约\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      0.注销登录\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "请选择您的操作：" << endl;
}
//申请预约
void student::applyorder()
{
	cout << "机房开放时间为周一到周五！" << endl;
	cout << "请输入申请预约的时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请输入申请时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "请选择机房的编号：" << endl;
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].c_id << "号机房的最大容量为" << vcom[i].max_size << endl;
	}
	cout << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功，待审核！" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	//向文件中写入数据 以追加的形式
	ofs << "date: "<< date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuid:" << this->my_id << " ";
	ofs << "stuname:" << this->my_name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}
//查看自身预约
void student::showmyorder()
{
	orderfile ofs;
	if (ofs.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	//string 利用C语言风格完成转换 再利用atoi 把 char 转换为 int
	for (int i = 0; i < ofs.m_size; i++)
	{
		if (this->my_id == atoi(ofs.m_orderdata[i]["stuid"].c_str()))
		{
			//找到自身预约
			cout << "预约日期：周" << ofs.m_orderdata[i]["date"];
			cout << " 时间段:  " << ((ofs.m_orderdata[i]["intercal"] == "1" )? "上午" : "下午");
			cout << "机房号： " << ofs.m_orderdata[i]["roomid"];
			string status = "状态：";
			//1 审核中 2.已预约 -1 预约失败 0取消预约
			if (ofs.m_orderdata[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (ofs.m_orderdata[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (ofs.m_orderdata[i]["status"] == "-1")
			{
				status += "预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << "状态：" << status << endl;
		}
	}
	system("pause");
	system("cls");
	//输出完全 清空 摁任意键继续
}
//查看所有预约
void student::showallorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << " ";
		cout << " 预约日期：周" << of.m_orderdata[i]["date"];
		cout << " 学号：" << of.m_orderdata[i]["stuid"];
		cout << " 姓名：" << of.m_orderdata[i]["stuname"];
		cout << " 机房：" << of.m_orderdata[i]["roomid"];
		string status = "状态：";
		//0 取消的预约 1 审核中 2 已预约 -1 预约失败
		if (of.m_orderdata[i]["status"] == "0")
		{
			status += "预约已取消";
		}
		else if (of.m_orderdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else
		{
			status += "预约失败";
		}
		cout << " 状态：" << status << endl;
	}
	system("pause");
	system("cls");
}
//取消预约
void student::cancelorder()
{
	orderfile ofs;
	if (ofs.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int> v;
	cout << "处于审核中或者预约成功的记录可以取消，请输入要取消的记录" << endl;
	int index = 1;
	for (int i = 0; i < ofs.m_size; i++)
	{
		//先判断是否是自身的学号
		if (this->my_id == atoi(ofs.m_orderdata[i]["stuid"].c_str()))
		{
			//筛选出可以取消预约的记录
			if (ofs.m_orderdata[i]["stuid"] == "1" || ofs.m_orderdata[i]["stuid"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期： 周" << ofs.m_orderdata[i]["date"];
				cout << "预约时间段：" << (ofs.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房编号：" << ofs.m_orderdata[i]["roomid"];
				string status = "状态：";
				if (ofs.m_orderdata[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (ofs.m_orderdata[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入要取消的记录，0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				//修改文件中的下标位置
				ofs.m_orderdata[v[select - 1]]["status"] = "0";
				//及时更新文件
				ofs.updateorder ();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}