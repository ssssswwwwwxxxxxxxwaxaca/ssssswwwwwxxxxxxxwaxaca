#pragma once
#include <iostream>
#include "identity.h"
#include <string>��
#include "globalfile.h"
#include "orderfile.h"
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class teacher :public identity
{
public:
	//Ĭ�Ϲ���
	teacher();
	//�вι���
	teacher(int id, string name, string password);
	//�˵�����
	virtual void openmenu();
	//�鿴���е�ԤԼ
	void showallorder();
	//���ԤԼ
	void validorder();
	int m_id;//���һ����ʦ�ı��

};