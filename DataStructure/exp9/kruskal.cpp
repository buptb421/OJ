#include<iostream>

using namespace std;

#define VERTEX_NUM 10
#define EDGE_NUM 19

int getNum(char str[])
{
    char *p = str;
    int n = 0;
    while(*p != '\0')
    {
        n = n * 10 + *p - '0';
        p++;
    }
    return n;
}

typedef struct EDGE{
    char e1;
    char e2;
    int weight;
}edge;

typedef struct VERTEX{
    int set;
}vertex;

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
/*
void displayEdge(edge e)
{
	cout << '[' << e.e1 << ", " << e.e2 << ']' << e.weight;
}
*/
void getGraph(graph &g, edge e[])
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

void getEdge(graph g, edge e[])
{
	//cout << "Get edge:" << endl;
    int count = 0;
    for(int i = 0; i < VERTEX_NUM; i++)
    {
        for(int j = i + 1; j < VERTEX_NUM; j++)
        {
            if(g.m[i][j] != 0)
            {
                e[count].e1 = i + 'A';
                e[count].e2 = j + 'A';
                e[count].weight = g.m[i][j];
                //cout << "  " << e[count].e1 << ',' << e[count].e2 << ',' << e[count].weight << endl;
                count++;
            }
        }
    }
}

void sort(edge e[], int sortMap[])
{
	//cout << "Sort:" << endl;
	int temp;
    for(int i = 0; i < EDGE_NUM; i++)
    {
        for(int j = i; j < EDGE_NUM; j++)
        {
            if(e[sortMap[i]].weight > e[sortMap[j]].weight)
            {
            	//cout << sortMap[i] << ' ' << sortMap[j] << endl;
            	temp = sortMap[i];
            	sortMap[i] = sortMap[j];
            	sortMap[j] = temp;
            }
        }
    }
}
void mergeSet(int VSI[], int a, int b)
{
    b = VSI[b];
    a = VSI[a];
    for(int i = 0; i < VERTEX_NUM; i++)
    {
        if(VSI[i] == b)
        {
            VSI[i] = a;
        }
    }
}
void kruskal(edge e[], int selectMap[])
{
    int sortMap[EDGE_NUM] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
    };
    sort(e, sortMap);

    int vertexSetIndex[VERTEX_NUM] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    };
    int count = 0;
    for(int i = 0; i < EDGE_NUM; i++)
    {
        if(vertexSetIndex[getID(e[sortMap[i]].e1)] != vertexSetIndex[getID(e[sortMap[i]].e2)])
        {
            /*
            cout << "Try ";
            displayEdge(e[sortMap[i]]);
            cout << e[sortMap[i]].e1 << ": set[" << vertexSetIndex[getID(e[sortMap[i]].e1)] << "], " 
                << e[sortMap[i]].e2 << ": set[" << vertexSetIndex[getID(e[sortMap[i]].e2)]<< "]\nWhen set[]:  "; 
            for(int i = 0; i < VERTEX_NUM; i++)
            {
                cout << vertexSetIndex[i] << ',';
            }
            cout << endl;
            */
            mergeSet(vertexSetIndex, getID(e[sortMap[i]].e1), getID(e[sortMap[i]].e2));
            /*
            cout << "Then set[]: ";
            for(int i = 0; i < VERTEX_NUM; i++)
            {
                cout << vertexSetIndex[i] << ',';
            }
            cout << '\n' << endl;
            */
            count++;
            cout << e[sortMap[i]].weight << ',';
        }
    }
}

int main()
{
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
    // Get initial graph
    graph g;
    getGraph(g, e);

    // Change edge
    char str[10];
    cin.getline(str, 10);
    int n = getNum(str + 4);
    g.m[getID(str[0])][getID(str[2])] = n;
    g.m[getID(str[2])][getID(str[0])] = n;
    
    // Get new edge
    getEdge(g, e);
	
    // Kruskal
    //int selectMap[VERTEX_NUM];
    kruskal(e/*, selectMap*/);
    
    return 0;
}
