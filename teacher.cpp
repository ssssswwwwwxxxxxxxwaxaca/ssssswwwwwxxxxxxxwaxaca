#include "teacher.h"
//Ĭ�Ϲ���
teacher::teacher()
{

}
//�вι���
teacher::teacher(int id, string name, string password)
{
	this->m_id = id;
	this->my_name = name;
	this->my_password = password;
}
//�˵�����
void teacher::openmenu()
{
	cout << "��ӭ��ʦ" << this->my_name << "��¼��" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      1.�鿴����ԤԼ\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      2.���ԤԼ\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      0.ע����¼\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
}
//�鿴���е�ԤԼ
void teacher::showallorder()
{
	orderfile ofs;
	if (ofs.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < ofs.m_size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << ofs.m_orderdata[i]["date"];
		cout << " ԤԼʱ��Σ�" << (ofs.m_orderdata[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << ofs.m_orderdata[i]["stuid"];
		cout << " ������" << ofs.m_orderdata[i]["stuname"];
		cout << " ������ţ�" << ofs.m_orderdata[i]["roomid"];
		string status = "״̬��";
		//1 ����� 2 ԤԼ�ɹ� 0 ȡ��ԤԼ -1 ԤԼʧ��
		if (ofs.m_orderdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (ofs.m_orderdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (ofs.m_orderdata[i]["status"] == "0")
		{
			status += "ȡ��ԤԼ";
		}
		else
		{
			status += "ԤԼʧ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ
void teacher::validorder()
{
	orderfile ofs;
	if (ofs.m_size == 0)
	{
		cout << "��ԤԼ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int> v;
	int index = 0;
	for (int i = 0; i < ofs.m_size; i++)
	{
		if (ofs.m_orderdata[i]["status"] == "1")
		{
			//���ڴ���˵Ĳſ��Խ������
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼʱ�䣺��" << ofs.m_orderdata[i]["date"];
			cout << " ʱ��Σ�" << (ofs.m_orderdata[i]["interval"]=="1"?"����":"����");
			cout << " ������" << ofs.m_orderdata[i]["roomid"];
			 string status = "״̬��";
			//1 ����� 2 ԤԼ�ɹ� 0 ȡ��ԤԼ -1 ԤԼʧ��
			if (ofs.m_orderdata[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (ofs.m_orderdata[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (ofs.m_orderdata[i]["status"] == "0")
			{
				status += "ȡ��ԤԼ";
			}
			else
			{
				status += "ԤԼʧ��";
			}
			cout << status << endl;

		}
	}
	cout << "������Ҫ��˵�ԤԼ��¼ 0������" << endl;
	int select = 0;//�����û���ѡ��
	int ret;//���մ���Ľ��
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
				cout << "��������˽����" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
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
				cout << "�����ϣ�" << endl;
				break;
			}
			cout << "������������������" << endl;
		}
		
	}
	system("pause");
	system("cls");
}