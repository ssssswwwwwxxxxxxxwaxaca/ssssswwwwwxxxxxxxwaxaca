#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include "computerroom.h"
#include <string>
#include <vector>
#include <fstream>
#include "globalfile.h"
#include "orderfile.h"
class student :public identity//���๫���̳и���
{
public:
	//Ĭ�Ϲ���
	student();
	//�вι��� ���� ѧ�� ���� ����
	student(int id, string name, string password);
	//�˵�ҳ��
	virtual void openmenu() ;
	//����ԤԼ
	void applyorder();
	//�鿴����ԤԼ
	void showmyorder();
	//�鿴����ԤԼ
	void showallorder();
	//ȡ��ԤԼ
	void cancelorder();
	//ѧ����Ҫ���·�װ �����������Լ��û��� ����ͨ�� ֱ�Ӽ̳м���
	int my_id;
	//���һ��ԤԼ�����ļ�¼
	vector<computerroom> vcom;
};