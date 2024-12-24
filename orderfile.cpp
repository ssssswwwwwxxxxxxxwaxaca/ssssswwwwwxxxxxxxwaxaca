#include "orderfile.h"


//构造函数
orderfile::orderfile()
{

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	string date;//日期
	string interval;//时间段
	string stuid;//学生编号
	string stuname;//学生姓名
	string roomid;//机房编号
	string status;//预约状态
	this->m_size = 0;
	//记录的总条数
	while (ifs >> date && ifs >> interval && ifs >> stuid && ifs >> stuname && ifs >> roomid && ifs >> status)
	{


		string key;
		string value;
		map<string, string> m;
		int pos = -1;
		pos = date.find(":");
		if (pos != -1)
		{


			key = date.substr(0, pos);//取子串
			value = date.substr(pos + 1, date.size() - pos - 1);//截取的位置 截取的个数
		}
		m.insert(make_pair(key, value));
		//cout << "key= " << key << endl;
		//cout << "value= " << value << endl;
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);//取子串
			value = interval.substr(pos + 1, interval.size() - pos - 1);//截取的位置 截取的个数
			m.insert(make_pair(key, value));
		}
		pos = stuid.find(":");
		if (pos != -1)
		{
			key = stuid.substr(0, pos);//取子串
			value = stuid.substr(pos + 1, stuid.size() - pos - 1);//截取的位置 截取的个数
			m.insert(make_pair(key, value));
		}
		pos = stuname.find(":");
		if (pos != -1)
		{
			key = stuname.substr(0, pos);//取子串
			value = stuname.substr(pos + 1, stuname.size() - pos - 1);//截取的位置 截取的个数
			m.insert(make_pair(key, value));
		}

		pos = roomid.find(":");
		if (pos != -1)
		{
			key = roomid.substr(0, pos);//取子串
			value = roomid.substr(pos + 1, roomid.size() - pos - 1);//截取的位置 截取的个数
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);//取子串
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
			//截取的位置 截取的个数
		}
		
		//把小的map容器 插入到 大的map中去
		this->m_size++;
		this->m_orderdata.insert(make_pair(this->m_size, m));
	}
	ifs.close();
	
}
//更新预约记录
void orderfile::updateorder()
{
	if (this->m_size == 0)
	{
		return;//零预约记录 直接结束即可
	}
	ofstream ofs(ORDER_FILE, ios::out|ios::trunc);
	//打开并完成删除里面的内容
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