#include "student.h"
//Ĭ�Ϲ���
student::student()
{

}
//�вι��� ���� ѧ�� ���� ����
student::student(int id, string name, string password)
{
	this->my_id=id;
	this->my_name = name;
	this->my_password = password;
	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);//��ȡ�ļ�
	computerroom c;
	while (ifs >> c.c_id && ifs >> c.max_size)
	{
		this->vcom.push_back(c);
	}
	ifs.close();
}
//�˵�����
void student::openmenu()
{
	cout << "��ӭѧ��" << this->my_name << "��¼��" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      1.����ԤԼ\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      2.�鿴�ҵ�ԤԼ\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      3.�鿴����ԤԼ\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      4.ȡ��ԤԼ\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      0.ע����¼\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
}
//����ԤԼ
void student::applyorder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
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
		cout << "������������������" << endl;
	}
	cout << "����������ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "��ѡ������ı�ţ�" << endl;
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].c_id << "�Ż������������Ϊ" << vcom[i].max_size << endl;
	}
	cout << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ�������ˣ�" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	//���ļ���д������ ��׷�ӵ���ʽ
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
//�鿴����ԤԼ
void student::showmyorder()
{
	orderfile ofs;
	if (ofs.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	//string ����C���Է�����ת�� ������atoi �� char ת��Ϊ int
	for (int i = 0; i < ofs.m_size; i++)
	{
		if (this->my_id == atoi(ofs.m_orderdata[i]["stuid"].c_str()))
		{
			//�ҵ�����ԤԼ
			cout << "ԤԼ���ڣ���" << ofs.m_orderdata[i]["date"];
			cout << " ʱ���:  " << ((ofs.m_orderdata[i]["intercal"] == "1" )? "����" : "����");
			cout << "�����ţ� " << ofs.m_orderdata[i]["roomid"];
			string status = "״̬��";
			//1 ����� 2.��ԤԼ -1 ԤԼʧ�� 0ȡ��ԤԼ
			if (ofs.m_orderdata[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (ofs.m_orderdata[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (ofs.m_orderdata[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << "״̬��" << status << endl;
		}
	}
	system("pause");
	system("cls");
	//�����ȫ ��� �����������
}
//�鿴����ԤԼ
void student::showallorder()
{
	orderfile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << " ";
		cout << " ԤԼ���ڣ���" << of.m_orderdata[i]["date"];
		cout << " ѧ�ţ�" << of.m_orderdata[i]["stuid"];
		cout << " ������" << of.m_orderdata[i]["stuname"];
		cout << " ������" << of.m_orderdata[i]["roomid"];
		string status = "״̬��";
		//0 ȡ����ԤԼ 1 ����� 2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderdata[i]["status"] == "0")
		{
			status += "ԤԼ��ȡ��";
		}
		else if (of.m_orderdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else
		{
			status += "ԤԼʧ��";
		}
		cout << " ״̬��" << status << endl;
	}
	system("pause");
	system("cls");
}
//ȡ��ԤԼ
void student::cancelorder()
{
	orderfile ofs;
	if (ofs.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int> v;
	cout << "��������л���ԤԼ�ɹ��ļ�¼����ȡ����������Ҫȡ���ļ�¼" << endl;
	int index = 1;
	for (int i = 0; i < ofs.m_size; i++)
	{
		//���ж��Ƿ��������ѧ��
		if (this->my_id == atoi(ofs.m_orderdata[i]["stuid"].c_str()))
		{
			//ɸѡ������ȡ��ԤԼ�ļ�¼
			if (ofs.m_orderdata[i]["stuid"] == "1" || ofs.m_orderdata[i]["stuid"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ� ��" << ofs.m_orderdata[i]["date"];
				cout << "ԤԼʱ��Σ�" << (ofs.m_orderdata[i]["interval"] == "1" ? "����" : "����");
				cout << "������ţ�" << ofs.m_orderdata[i]["roomid"];
				string status = "״̬��";
				if (ofs.m_orderdata[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (ofs.m_orderdata[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������Ҫȡ���ļ�¼��0������" << endl;
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
				//�޸��ļ��е��±�λ��
				ofs.m_orderdata[v[select - 1]]["status"] = "0";
				//��ʱ�����ļ�
				ofs.updateorder ();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}