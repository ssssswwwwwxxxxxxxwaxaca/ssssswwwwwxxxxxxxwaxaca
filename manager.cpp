#include "manager.h"
#include <fstream>
#include "globalfile.h"
#include <iomanip>
//Ĭ�Ϲ���
manager::manager()
{

}
//�вι���
manager::manager(string name, string password)
{
	//����Ա���в���� ��� ����Ҫ�û�����������ɾ���
	this->my_name = name;
	this->my_password = password;
	this->initvector();
	//�вι����ͬʱ��ɳ�ʼ������
	//��ʼ��������Ϣ ����������ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);//���ļ��������д����
	computerroom com;
	while (ifs >> com.c_id && ifs >> com.max_size)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << vcom.size() << endl;
}
//�˵�����
void manager::openmenu()
{
	cout << "��ӭ����Ա" << this->my_name << "��¼��" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      1.����˺�\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      2.�鿴�˺�\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      3.�鿴����\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      4.���ԤԼ\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "\t\t      0.ע����¼\n" << endl;
	cout << "\t\t-----------------------------------\n" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;
 }
//����˺�
void manager::addperson()
{
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	string filename;
	string tip;
	string errortip;
	ofstream ofs;//���ļ�����д��
	int select;
	cin >> select;
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ����ѧ�ŷ����ظ�������������";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errortip = "��ʦ��ְ���ŷ����ظ�������������";
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string mypassword;
	while (1)
	{
		cout << tip << endl;//���������ʾ��
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
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> mypassword;
	ofs << id << " " << name << " " << mypassword << endl;//������д�뵽�ļ���
	cout << "��ӳɹ�������" << endl;
	this->initvector();//�ļ��������� ��ʱ����ϵͳ��
	system("pause");
	system("cls");
	ofs.close();
}
//�鿴�˺�
void manager::showperson()
{
	cout << "ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;
	int select=0;
	cin >> select;
	if (select == 1)
	{
		//�鿴���е�ѧ��
		cout << left;
		cout <<setw(10) <<"ѧ��" << setw(10) << "�û���" << setw(10) << "����" << endl;
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			cout << setw(10) << (*it).my_id << setw(10) << (*it).my_name << setw(10) << (*it).my_password << endl;
		}
		cout << "-------------------------------------------------------------------------" << endl;
	}
	else
	{
		//�鿴��ʦ
		cout << left;
		cout << setw(10)<<"ְ����" << setw(10) << "�û���" << setw(10) << "����" << endl;
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			cout << (*it).m_id << setw(10) << (*it).my_name << setw(10) << (*it).my_password << endl;
		}
		cout << "------------------------------------------------------------------------" << endl;
	}
}
//�鿴������Ϣ
void manager::showcomputer()
{
	cout << "��������Ϣ���£�" << endl;
	for (vector<computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++)
	{
		cout << "������ţ�" << (*it).c_id << "     " << "��������" << (*it).max_size << endl;
	}
	system("pause");
	system("cls");

}
//���ԤԼ��¼
void manager::clearorder()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}
void manager::initvector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	student s;
	while (ifs >> s.my_id && ifs >> s.my_name && ifs >> s.my_password)
	{
		vstu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ��" << vstu.size() << endl;
	ifs.close();//ѧ����ʼ����� �ر��ļ�

	//��ȡ��ʦ���ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
	}
	teacher t;
	while (ifs >> t.m_id && ifs >> t.my_name && ifs >> t.my_password)
	{
		vtea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ��" << vtea.size() << endl;
	ifs.close();
}
bool manager::checkrepeat(int id,int type)
{
	if (type == 1)
	{
		//��ѧ��������ɼ��
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