#include "teacher.h"
//默认构造
teacher::teacher()
{

}
//有参构造
teacher::teacher(int id, string name, string password)
{
	this->m_id = id;
	this->my_name = name;
	this->my_password = password;
}
//菜单界面
void teacher::openmenu()
{
	cout << "欢迎教师" << this->my_name << "登录！" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      1.查看所有预约\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      2.审核预约\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      0.注销登录\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "请选择您的操作：" << endl;
}
//查看所有的预约
void teacher::showallorder()
{
	orderfile ofs;
	if (ofs.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < ofs.m_size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << ofs.m_orderdata[i]["date"];
		cout << " 预约时间段：" << (ofs.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << ofs.m_orderdata[i]["stuid"];
		cout << " 姓名：" << ofs.m_orderdata[i]["stuname"];
		cout << " 机房编号：" << ofs.m_orderdata[i]["roomid"];
		string status = "状态：";
		//1 审核中 2 预约成功 0 取消预约 -1 预约失败
		if (ofs.m_orderdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (ofs.m_orderdata[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (ofs.m_orderdata[i]["status"] == "0")
		{
			status += "取消预约";
		}
		else
		{
			status += "预约失败";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//审核预约
void teacher::validorder()
{
	orderfile ofs;
	if (ofs.m_size == 0)
	{
		cout << "无预约待审核" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < ofs.m_size; i++)
	{
		if (ofs.m_orderdata[i]["status"] == "1")
		{
			//处于待审核的才可以进行审核
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约时间：周" << ofs.m_orderdata[i]["date"];
			cout << " 时间段：" << (ofs.m_orderdata[i]["interval"]=="1"?"上午":"下午");
			cout << " 机房：" << ofs.m_orderdata[i]["roomid"];
			 string status = "状态：";
			//1 审核中 2 预约成功 0 取消预约 -1 预约失败
			if (ofs.m_orderdata[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (ofs.m_orderdata[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (ofs.m_orderdata[i]["status"] == "0")
			{
				status += "取消预约";
			}
			else
			{
				status += "预约失败";
			}
			cout << status << endl;

		}
	}
	cout << "请输入要审核的预约记录 0代表返回" << endl;
	int select = 0;//接收用户的选择
	int ret;//接收处理的结果
	while (true)
	{
		if (select >= 0 && select < v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果：" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					ofs.m_orderdata[v[select - 1]]["status"] = "2";
				}
				else
				{
					ofs.m_orderdata[v[select - 1]]["status"] == "-1";
				}
				ofs.updateorder();
				cout << "审核完毕！" << endl;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
	}
	system("pause");
	system("cls");
}