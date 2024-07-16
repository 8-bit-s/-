/*
*User.h
*��������Ա�ĵ�¼���ܣ��Լ���ɾ�Ĳ飻������ͨ�û�������·�߲�ѯ
*/

#pragma once
using namespace std;
#include<vector>
#include<string>
#include"Graph.h"
#include"TripTable.h"
static const char* KEY = "pvViCH5F";//����Ա��Կ

/*��ͨ�û���*/
class User {
public:
	/*
	*����·���㷨
	* ���ܣ������û�ѡ��ĳ��У����з�ʽ���������ݵõ�����·��
	* ���룺ʼ��վ(City),�յ�վ(City),���з�ʽ(int)����������(int)
	* ����ֵ������·����Ϣ
	*/
	string bestRoute(const City& src, const City& arv, int tripType, int method);
};



/*����Ա��*/
class Admin {
private:
	bool isOnline;
public:
	Admin() :isOnline(0){}

	bool getOnline() {
		return isOnline;
	}

	bool logIn(string key1);

	void logOut();
};

/*
*�����⺯��������������
*/
bool isCity(string name1);

bool isCost(string cost1);

bool isDist(string dist1);

bool isHour(string hour1);

bool isMinute(string minute1);