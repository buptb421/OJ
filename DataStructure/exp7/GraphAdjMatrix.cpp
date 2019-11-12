#include<new>
#include<iostream>
#include<queue>

#define VERTEX_NUM 11
#define EDGE_NUM 21
#define nullptr NULL

using namespace std;

int getID(char vertexName[VERTEX_NUM], char name)
{
    for(int i = 0; i < VERTEX_NUM; i++)
    {
        if(vertexName[i] == name)
        {
            return i;
        }
    }
    cout << "Vertex not found." << endl;
    return -1;
}

bool getTuple(char vertexName[VERTEX_NUM], int tup[EDGE_NUM][2])
{
    char a[21][3] = {
        "SA", "SD", "SG",
        "AB", "AE", "BC",
        "CT", "DA", "DE",
        "EC", "EF", "EI",
        "FC", "FT", "GD",
        "GE", "GH", "HE",
        "HI", "IF", "IT",
    };

    char del_f, comma, del_t;// Delete from, delete to
    cin >> del_f >> comma >> del_t;
    
    bool found_edge = false;
    int iw = 0;// index of written line
    for(int i = 0; i < EDGE_NUM; i++)
    {
        if(a[i][0] != del_f || a[i][1] != del_t)
        {
            tup[iw][0] = getID(vertexName, a[i][0]);
            tup[iw][1] = getID(vertexName, a[i][1]);
            if(tup[iw][0] == -1 || tup[iw][1] == -1)
            {
                cout << "Since vertex not found, construction of list of edges abort." << endl;
                return false;
            }
            iw++;
        }
        else
        {
            found_edge = true;
        }
    }
    return found_edge;
}

typedef struct GRAPH_ADJ_LIST{
    int vertexNum;
    int edgeNum;
    int indegree[VERTEX_NUM];
    bool adjM[VERTEX_NUM][VERTEX_NUM];
}graph;
/*
void displayGraph(graph g)
{
    char vertexName[VERTEX_NUM] = {
        'S', // 0
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'T', // 10
    };
    cout << "Vertex: " << g.vertexNum << ", Edges: " << g.edgeNum << '{' << endl
         << "Indegree: ";
    for(int i = 0; i < g.vertexNum; i++)
    {
        cout << vertexName[i] << ':' << g.indegree[i] << ',';
    }
    cout << endl
         << "  ";
    for(int i = 0; i < g.vertexNum; i++)
    {
        cout << vertexName[i];
    }
    for(int i = 0; i < g.vertexNum; i++)
    {
        cout << endl
             << vertexName[i] << ' ';
        for(int j = 0; j < g.vertexNum; j++)
        {
            if(g.adjM[i][j])// == true
            {
                cout << '1';
            }
            else
            {
                cout << '0';
            }
        }

    }
    cout << endl
         << '}' << endl;
}
*/
void buildGraph(int vertexNum, int edgeNum, int tup[][2], graph &g)
{
    g.vertexNum = vertexNum;
    g.edgeNum = edgeNum;

    for(int i = 0; i < vertexNum; i++)// init
    {
        g.indegree[i] = 0;
        for(int j = 0; j < vertexNum; j++)
        {
            g.adjM[i][j] = false;
        }
    }

    for(int i = 0; i < edgeNum; i++)
    {
        g.adjM[ tup[i][0] ] [ tup[i][1] ] = true;// get the matrix
        g.indegree[ tup[i][1] ]++;// get indegree
    }
}

void divVertex(graph &g, int n, queue<int> &zeroVertex)
{
    for(int i = 0; i < g.vertexNum; i++)
    {
        if(g.adjM[n][i])// == true
        {
            g.edgeNum--;
            g.indegree[i]--;
            if(g.indegree[i] == 0)
            {
                zeroVertex.push(i);
            }
            g.adjM[n][i] = false;    
        }
    }
}

void topologySort(char vertexName[VERTEX_NUM], graph g)
{
    queue<int> zeroVertex;
    for(int i = 0; i < g.vertexNum; i++)
    {
        if(g.indegree[i] == 0)
        {
        	zeroVertex.push(i);
		}
    }
    while(!zeroVertex.empty())
    {
        divVertex(g, zeroVertex.front(), zeroVertex);
        // this function divide a zero indegree vertex out of the graph(break the connectivity)

        cout << vertexName[zeroVertex.front()] << ',';
        zeroVertex.pop();
    }
}

int main()
{
    char vertexName[VERTEX_NUM] = {
        'S', // 0
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'T', // 10
    };
    int tup[EDGE_NUM][2];
    if(getTuple(vertexName, tup))
    {
        graph g;
        buildGraph(VERTEX_NUM, EDGE_NUM - 1, tup, g);
        //displayGraph(g);
        topologySort(vertexName, g);
        return 0;
    }
    else
    {
        cout << "Edge list wrong, abort program." << endl;
        return 1;
    }
}

