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

typedef Node(*Matrix)[MAXCITY];//一行

class Graph {//用于算法的图
public:
    Matrix matrix;
    
    Graph();

    //~Graph();

    int init(Menu m);

    void Dijkstra(Matrix, int, int, int, int);

    void printTrips(const City& stf, const City& arv);//测试用函数
private:
    int numV;//顶点数，即城市数
    int numE;//边数
    
};