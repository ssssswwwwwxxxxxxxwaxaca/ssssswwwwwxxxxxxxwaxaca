#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "globalfile.h"
#include <map>
using namespace std;
class orderfile
{
public:
	//���캯��
	orderfile();
	//����ԤԼ��¼
	void updateorder();
	//��¼ԤԼ����
	int m_size;
	//��¼����ԤԼ��Ϣ������
	map<int, map<string, string>> m_orderdata;
};

