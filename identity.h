#pragma once//��ֹͷ�ļ��ظ�����
#include <string>
#include <iostream>
using namespace std;
//��ݳ����࣬��װ �̳� ��̬
class identity
{
public:
	//�����˵�
	virtual void openmenu() = 0;//дһ�����麯��
	//�û���
	string my_name;
	//����
	string my_password;

};