#pragma once

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 6//������Ҳ�Ƕ�����
const int INF = INT_MAX;

enum TripType{AIR,RAIL};

class Trip 
{
public:
    int src;
    int dest;
    int Time;
    int Cost;  
    TripType triptype;
};

//��Node��װTrip**��������չ
class Node
{
public:
    Trip** Sdata;//SourceData
    int data;      
    Node()
    {
        Sdata = NULL;
        data = 0;
    }
    //��ʽ�ͽ�ͨ�����ھ������� 
    //����Trip*���鲢����Ӧ�������ҵ�Ȩֵ
    void Choose(int tripType, int method)
    {
        int sw = tripType * 10 + method;
        switch(sw)
        {
        case 0:
            Trip * p=*Sdata;
            data = p->Time;
            while(p!=NULL)
            {
                p = p->next;//��Ӧ�Ľṹ��������Ա���
                if
            }
            break;
        case 1://ά�ֵ�һ����֧�Ľṹ����
            break;
        case 10:
            break;
        case 11:
            break;
        default:
            break;
        }
    };
    int operator+(int n)
    {
        return this->data + n;
    }
    bool operator<(Node&n)
    {
        return this->data < n.data;
    }
};

class Graph
{
public:
	Graph()
    {
        //��ȡ���ݽ�ͼ
        //�ɶ�Ӧ�ṹ����
    }
    Node gragh[V][V];
    void Dijkstra(Node** graph, int src, int dest, int tripType, int method);
};

void Graph::Dijkstra(Node** g, int src, int dest,int tripType, int method)
{
    //��һ���֣���ͼ��ЧΪintͼ
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(g[i][j].Sdata!=NULL)
            {
                g[i][j].Choose(tripType,method);//����Ȩֵ
            }
        }
    }

    //�ڶ����֣������㷨
    int v = src;//�򻯱�������
    int dist[V];
    int path[V];
    int S[V];
    for(int i=0;i<V;i++)
    {
        dist[i] = g[v][i].data;
        S[i] = 0;
        if (g[v][i].data != 0 && g[v][i].data < INF)
            path[i] = v;
        else
            path[i] = -1;
    }
    S[v] = 1;
    int mindus = -1;
    int u = -1;
    for(int i=0;i<V-1;i++)
    {
        mindus = INF;
        for(int j=0;j<V;j++)
        {
            if(S[j]==0&&dist[j]<mindus)
            {
                u = j;
                mindus = dist[j];
            }
        }
        S[u] = 1;
        for(int j=0;j<V;j++)
        {
            if(S[j]==0)
                if (g[u][j].data < INF && g[u][j] + dist[u] < dist[j])
                {
                    dist[j] = g[u][j] + dist[u];
                    path[j] = u;
                }
        }
    }

    //�������֣���ӡ·���ͽ��������ǰ�˲�ͬ�ı�
    int i = dest;
    if (S[i] == 1 && i != v)
    {
        vector<int> apath;
        cout << dist[i];
        apath.push_back(i);
        int pre = path[i];
        while (pre != v)
        {
            apath.push_back(i);
            pre = path[pre];
        }
        cout << v;
        for (int k = apath.size() - 1; k >= 0; k--)
            cout << apath[k];
    }
    else
        cout << "NOPath";
}
