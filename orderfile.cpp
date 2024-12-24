#include "orderfile.h"


//���캯��
orderfile::orderfile()
{

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string date;//����
	string interval;//ʱ���
	string stuid;//ѧ�����
	string stuname;//ѧ������
	string roomid;//�������
	string status;//ԤԼ״̬
	this->m_size = 0;
	//��¼��������
	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status)
	{


		string key;
		string value;
		map<string, string> m;
		int pos = -1;
		pos = date.find(":");
		if (pos != -1)
		{


			key = date.substr(0, pos);//ȡ�Ӵ�
			value = date.substr(pos + 1, date.size() - pos - 1);//��ȡ��λ�� ��ȡ�ĸ���
		}
		m.insert(make_pair(key, value));
		//cout << "key= " << key << endl;
		//cout << "value= " << value << endl;
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);//ȡ�Ӵ�
			value = interval.substr(pos + 1, interval.size() - pos - 1);//��ȡ��λ�� ��ȡ�ĸ���
			m.insert(make_pair(key, value));
		}
		pos = stuid.find(":");
		if (pos != -1)
		{
			key = stuid.substr(0, pos);//ȡ�Ӵ�
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);//��ȡ��λ�� ��ȡ�ĸ���
			m.insert(make_pair(key, value));
		}
		pos = stuname.find(":");
		if (pos != -1)
		{
			key = stuname.substr(0, pos);//ȡ�Ӵ�
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);//��ȡ��λ�� ��ȡ�ĸ���
			m.insert(make_pair(key, value));
		}

		pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);//ȡ�Ӵ�
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);//��ȡ��λ�� ��ȡ�ĸ���
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);//ȡ�Ӵ�
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
			//��ȡ��λ�� ��ȡ�ĸ���
		}
		
		//��С��map���� ���뵽 ���map��ȥ
		this->m_size++;
		this->m_orderdata.insert(make_pair(this->m_size, m));
	}
	ifs.close();
	
}
//����ԤԼ��¼
void orderfile::updateorder()
{
	if (this->m_size == 0)
	{
		return;//��ԤԼ��¼ ֱ�ӽ�������
	}
	ofstream ofs(ORDER_FILE, ios::out|ios::trunc);
	//�򿪲����ɾ�����������
	for (int i = 0; i < m_size; i++)
	{
		ofs << "date:" << this->m_orderdata[i]["date"] << " ";
		ofs << "interval:" << this->m_orderdata[i]["interval"] << " ";
		ofs << "stuid:" << this->m_orderdata[i]["stuid"] << " ";
		ofs << "stuname:" << this->m_orderdata[i]["stuname"] << " ";
		ofs << "roomid:" << this->m_orderdata[i]["roomid"] << " ";
		ofs << "status:" << this->m_orderdata[i]["status"] << " " << endl;
	}
	ofs.close();
}