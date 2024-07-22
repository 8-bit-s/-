#include"TripTable.h"
#include<iostream>
#include<vector>
#include"Graph.h"

using namespace std;

#define V MAXCITY
#define g matrix
//Node g[V][V];

const int INF = INT_MAX;
const float weight1=0.5;
const float weight2=0.05;

void Node::choose(int tripType, int method)
{
    int sw = tripType * 10 + method;
    int max = Sdata.size();
    data = INF;
    switch (sw)
    {
    case 0:
       for(int i=0;i<max;i++)
       {
           if (Sdata[i].type == AIR)
           {
               if (Sdata[i].time.minutes()< data)
               {
                   data = Sdata[i].time.minutes();
                   id = Sdata[i].id;
               }
           }
       }
        break;
    case 10:
        for (int i = 0; i < max; i++)
        {
            if (Sdata[i].type == RAIL)
            {
                if (Sdata[i].time.minutes() < data)
                {
                    data = Sdata[i].time.minutes();
                    id = Sdata[i].id;
                }
            }
        }
        break;
    case 1:
        for (int i = 0; i < max; i++)
        {
            if (Sdata[i].type == AIR)
            {
                if (Sdata[i].cost< data)
                {
                    data = Sdata[i].cost;
                    id = Sdata[i].id;
                }
            }
        }
        break;
    case 11:
        for (int i = 0; i < max; i++)
        {
            if (Sdata[i].type == RAIL)
            {
                if (Sdata[i].cost < data)
                {
                    data = Sdata[i].cost;
                    id = Sdata[i].id;
                }
            }
        }
        break;
    case 21:
        for (int i = 0; i < max; i++)
        {
            if (Sdata[i].cost < data)
            {
                data = Sdata[i].cost;
                id = Sdata[i].id;
            }
        }
        break;
    case 20:
        for (int i = 0; i < max; i++)
        {
            if (Sdata[i].time.minutes() < data)
            {
                data = Sdata[i].time.minutes();
                id = Sdata[i].id;
            }
        }
        break;
    case 2:
        for (int i = 0; i < max; i++)
        {
            if (Sdata[i].type == AIR)
            {
                if ((Sdata[i].time.minutes()*weight1+ Sdata[i].cost*weight2)< data)
                {
                    data = Sdata[i].time.minutes() * weight1 + Sdata[i].cost * weight2;
                    id = Sdata[i].id;
                }
            }
        }
        break;
    case 12:
        for (int i = 0; i < max; i++)
        {
            if (Sdata[i].type == RAIL)
            {
                if ((Sdata[i].time.minutes() * weight1 + Sdata[i].cost * weight2) < data)
                {
                    data = Sdata[i].time.minutes() * weight1 + Sdata[i].cost * weight2;
                    id = Sdata[i].id;
                }
            }
        }
        break;
    case 22:
        for (int i = 0; i < max; i++)
        {
            if ((Sdata[i].time.minutes() * weight1 + Sdata[i].cost * weight2) < data)
            {
              data = Sdata[i].time.minutes() * weight1 + Sdata[i].cost * weight2;
              id = Sdata[i].id;
            }
        }
    default:
        break;
    }
};

int Node::operator+(int n)
{
    return this->data + n;
}

bool Node::operator<(Node& n)
{
    return this->data < n.data;
}

vector<Trip> Graph::Dijkstra(vector<Trip>trips, int src, int dest, int tripType, int method)
{
    //第一部分，将图等效为int图
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (!g[i][j].Sdata.empty())
            {
                g[i][j].choose(tripType, method);//赋予权值
            }
        }
    }

    //第二部分，主体算法
    int v = src;//简化变量名称
    int dist[V];
    int path[V];
    int S[V];
    for (int i = 0; i < V; i++)
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
    for (int i = 0; i < V - 1; i++)
    {
        mindus = INF;
        for (int j = 0; j < V; j++)
        {
            if (S[j] == 0 && dist[j] < mindus)
            {
                u = j;
                mindus = dist[j];
            }
        }
        if (u == -1) {
            vector<Trip>empty;
            return empty;
        }
        S[u] = 1;
        for (int j = 0; j < V; j++)
        {
            if (S[j] == 0)
                if (g[u][j].data < INF && g[u][j] + dist[u] < dist[j])
                {
                    dist[j] = g[u][j] + dist[u];
                    path[j] = u;
                }
        }
    }

    //第三部分，打印路径和结果，根据前端不同改变
    int i = dest;
    vector<Trip> answer;
    if (S[i] == 1 && i != v)
    {
        vector<int> apath;
        vector<Trip> answer;
        apath.push_back(i);
        int pre = path[i];
        while (pre != v)
        {
            apath.push_back(pre);
            pre = path[pre];
        }
        apath.push_back(src);
        for (int k = apath.size() - 1; k >= 1; k--)
        {
            int tmp = k - 1;
            answer.push_back(trips[g[apath[k]][apath[tmp]].id]);
        }
        return answer;
    }
    else
    {
        vector<Trip> empty;
        return  empty;
    }
}
