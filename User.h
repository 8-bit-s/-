/*
*User.h
*��������Ա�ĵ�¼���ܣ��Լ���ɾ�Ĳ飻������ͨ�û�������·�߲�ѯ
*
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

	bool logIn(string key1);

	void logOut();

	void AddCity(Menu& menu, string name1);

	void AddTrip(Menu& menu, City stfCity1, City arvCity1, string cost1, string dist1, string hour1,
		string minute1, Triptype type1) throw(cinErr);

	void UpdateCity(Menu& menu, City tarCity, string name1);
	
	void UpdateTrip(Menu& menu, vector<TripNode*>tripList, int index, City stfCity1, City arvCity1,
		string cost1, string dist1, string hour1, string minute1, Triptype type1) throw(cinErr);

	void DeleteCity(Menu& menu, City tarCity);

	void DeleteTrip(Menu& menu,vector<TripNode*>tripList, int index);
};