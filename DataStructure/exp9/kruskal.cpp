#include<iostream>

using namespace std;

#define VERTEX_NUM 10
#define EDGE_NUM 19

typedef struct EDGE{
    char e1;
    char e2;
    int weight;
}edge;

edge e[EDGE_NUM] = {
    {'D', 'A', 4,},
    {'D', 'E', 5,},
    {'D', 'H', 6,},
    {'A', 'B', 3,},
    {'A', 'E', 4,},
    {'E', 'B', 2,},
    {'E', 'F', 11,},
    {'E', 'I', 1,},
    {'E', 'H', 2,},
    {'H', 'I', 4,},
    {'B', 'C', 10,},
    {'B', 'F', 3,},
    {'F', 'C', 6,},
    {'F', 'G', 2,},
    {'F', 'J', 11,},
    {'F', 'I', 3,},
    {'I', 'J', 7,},
    {'C', 'G', 1,},
    {'G', 'J', 8,},
};

int getID(char c)
{
    if(c >= 'A' && c <= 'J')
    {
        return c - 'A';
    }
    else
    {
        cout << "Error";
        return 0;
    }
}

typedef struct Graph_ADJ_Matrix{
    int vn;
    int en;
    int m[VERTEX_NUM][VERTEX_NUM];
}graph;

void getGraph(graph &g)
{
    g.vn = VERTEX_NUM;
    g.en = EDGE_NUM;
    for(int i = 0; i < g.vn; i++)
    {
        for(int j = 0; j < g.vn; j++)
        {
            g.m[i][j] = 0;
        }
    }
    for(int i = 0; i < g.en; i++)
    {
        g.m[getID(e[i].e1)][getID(e[i].e2)] = e[i].weight;
        g.m[getID(e[i].e2)][getID(e[i].e1)] = e[i].weight;
    }
}

void Sort(graph g, int e[][3])
{

}

void kruskal(graph g)
{

}