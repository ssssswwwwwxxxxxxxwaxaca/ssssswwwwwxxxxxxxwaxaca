#pragma once
#include <iostream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerroom.h"
using namespace std;
#include "identity.h"
//����Ա��������
class manager :public identity
{
public:
	//Ĭ�Ϲ���
	manager();
	//�вι���
	manager(string name,string password);
	//�˵�����
	virtual void openmenu();
	//����˺�
	void addperson();
	//�鿴�˺�
	void showperson();
	//�鿴������Ϣ
	void showcomputer();
	//���ԤԼ��¼
	void clearorder();
	void initvector();
	vector<student> vstu;
	vector<teacher> vtea;
	bool checkrepeat(int id,int type);
	vector<computerroom> vcom;
};