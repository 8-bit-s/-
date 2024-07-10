#pragma once
#include "oldTripTable.h"

class Node
{
public:
    TripNode** Sdata;//SourceData
    int data;
    Node();
    void choose(int tripType, int method);
    int operator+(int n);
    bool operator<(Node& n);
};

typedef Node(*Matrix)[MAXCITY];//һ��

class Graph {//�����㷨��ͼ
public:
    Matrix matrix;
    
    Graph();

    //~Graph();

    int init(Menu m);

    void Dijkstra(Matrix, int, int, int, int);

    void printTrips(const City& stf, const City& arv);//�����ú���
private:
    int numV;//����������������
    int numE;//����
    
};