/*
*User.h
*��������Ա�ĵ�¼���ܣ��Լ���ɾ�Ĳ飻������ͨ�û�������·�߲�ѯ
*/

#pragma once
using namespace std;
#include<vector>
#include<string>
#include"Graph.h"
#include"oldTripTable.h"
const char* KEY = "pvViCH5F";//����Ա��Կ

/*��ͨ�û���*/
class User {
public:
	/*
	*����·���㷨
	* ���ܣ������û�ѡ��ĳ��У����з�ʽ���������ݵõ�����·��
	* ���룺ʼ��վ(City),�յ�վ(City),���з�ʽ(int)����������(int)
	* ����ֵ������·����Ϣ
	*/
	string bestRoute(Menu& menu, const City& src, const City& arv, int tripType, int method);
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

	/*
	*�б��ʼ��������������
	* ���ܣ��������Աδ��ѯ��ֱ���޸Ļ�ɾ�������ô˺�������list��ʼ����ԭMenu������Ϣ
	*/
	void listInit(Menu menu, vector<TripNode*>& list);
	
	/*
	*����Ա��¼
	* ���ܣ��Ƚ��������Կ�͹���Ա��Կ�������ͬ���¼�ɹ�������true������ʧ�ܣ�����false
	*/
	bool logIn(string key1);

	//����Ա�ǳ���������ԣ�
	void logOut();

	/*
	*��ӳ���
	* ���ܣ�����������ƣ��Զ�����sign����ţ�������Menu
	*/
	void AddCity(Menu& menu, string name1) throw (cinErr);

	/*
	*����г�
	* ���ܣ�����Ա�����г���Ϣ���ж��Ƿ�Ϸ���������Ϸ����׳�cinErr����󣨴�����ʾ��Ϣ��������Ϸ������Menu
	*/
	void AddTrip(Menu& menu, City stfCity1, City arvCity1, string cost1, string dist1, string hour1,
		string minute1, Triptype type1) throw(cinErr);

	/*
	*�޸ĳ���
	* ���ܣ�����Աѡ�����У�����������ƣ�����Ϸ����޸ģ����Ϸ��׳�cinErr����󣨴�����ʾ��Ϣ��
	*/
	void UpdateCity(Menu& menu, City tarCity, string name1) throw(cinErr);
	
	/*
	*�޸��г�
	* ���ܣ�����Ա��ԭMenu���г���Ϣ�����ҵõ����г���Ϣ���У�ѡ���г̣�indexΪ��Ӧ�����±꣩��
	* ������Ϣ������Ϸ����޸ģ����Ϸ��׳�cinErr����󣨴�����ʾ��Ϣ��
	* ע�⣺index������ǰ�˴��룬����û�δ��ѯ��tripList����ԭ���������Ԫ�أ�����listInit��������
	* ������ǲ�ѯ�����ķ���ֵ��
	*/
	void UpdateTrip(Menu& menu, vector<TripNode*>tripList, int index, City stfCity1, City arvCity1,
		string cost1, string dist1, string hour1, string minute1, Triptype type1) throw(cinErr);

	/*
	*ɾ������
	* ���ܣ�����Աѡ�����У���Menuɾ��
	*/
	void DeleteCity(Menu& menu, City tarCity);

	/*
	*ɾ���г�
	* ���ܣ�����Ա��ԭMenu���г���Ϣ�����ҵõ����г���Ϣ���У�ѡ���г̣�indexΪ��Ӧ�����±꣩����Menuɾ��
	* ע�⣺index������ǰ�˴��룬����û�δ��ѯ��tripList����ԭ���������Ԫ�أ�����listInit��������
	* ������ǲ�ѯ�����ķ���ֵ��
	*/
	void DeleteTrip(Menu& menu,vector<TripNode*>tripList, int index);
};