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

typedef struct ADJ_LIST_NODE{
    int vertexID; // the node(or we can call it edge) point to this vertex
    struct ADJ_LIST_NODE *next;
}adjedge;

typedef struct ADJ_LIST_HEAD{
    int vertexID;
    int indegree;
    adjedge *first;
}adjvertex;

typedef struct GRAPH_ADJ_LIST{
    int vertexNum;
    int edgeNum;
    adjvertex *vertexList;
    adjedge *edgeList;
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
    cout << "Vertex: " << g.vertexNum << ", Edges: " << g.edgeNum << '{' << endl;
    for(int i = 0; i < g.vertexNum; i++)
    {
        cout << "  " << vertexName[i] << ".in: " << g.vertexList[i].indegree << ",.out: ";
        adjedge *p = g.vertexList[i].first;
        while(p)// != nullptr
        {
            cout << vertexName[p->vertexID] << ", ";
            p = p->next;
        }
        cout << endl;
    }
    cout << '}' << endl;
}
*/
// The operations are actually linklist operations.
// We insert new node to the head of the link list.
adjvertex* constructHead_list(int vertexNum)
{
    adjvertex *p = new adjvertex[vertexNum];
    if(p)// != nullptr
    {
        for(int i = 0; i < vertexNum; i++)
        {
            p[i].vertexID = i;
            p[i].indegree = 0;
            p[i].first = nullptr;
        }
    }
    else
    {
       cout << "Memory overflow, head list." << endl; 
    }
    return p;
}

adjedge *constructNode_list(int edgeNum)
{
    return new adjedge[edgeNum];
}

void setNode(adjedge *p, int vertexID)
{
    p->vertexID = vertexID;
    p->next = nullptr;
}



void insertNode_head(adjvertex *phead, adjedge *pnode)
{
	
	if(phead->first == nullptr)
	{
		phead->first = pnode;
	}
	else
	{
		adjedge *next = phead->first, *prev = nullptr;
		while(next)// != nullptr
		{
			prev = next;
			next = prev->next;
		}
	    prev->next = pnode;
	}
	
}

graph buildGraph(int vertexNum, int edgeNum, int tup[][2])
{
    graph g;
    g.vertexNum = vertexNum;
    g.edgeNum = edgeNum;

    g.vertexList = constructHead_list(vertexNum);
    g.edgeList = constructNode_list(edgeNum);

    for(int i = 0; i < edgeNum; i++)
    {
        setNode(g.edgeList + i, tup[i][1]);
        insertNode_head(g.vertexList + tup[i][0], g.edgeList + i);
        g.vertexList[tup[i][1]].indegree++;
    }
    return g;
}

int divVertex(graph g, int n, queue<int> &zeroVertex)
{
    adjvertex *prevVertex = g.vertexList + n;
    adjedge *prevEdge = prevVertex->first;
	int count = 0;
	
    while(prevEdge != nullptr)
    {
        g.vertexList[prevEdge->vertexID].indegree--;
        if(g.vertexList[prevEdge->vertexID].indegree == 0)
        {
        	//cout << "push: " << prevVertex->vertexID << "->" << prevEdge->vertexID << endl;
            zeroVertex.push(prevEdge->vertexID);
        }
        count++;
        prevEdge = prevEdge->next;
        prevVertex->first = prevEdge;
    }
    return count;
}

bool topologySort(char vertexName[VERTEX_NUM], graph g)
{
    queue<int> zeroVertex;
    //displayGraph(g);
    for(int i = 0; i < g.vertexNum; i++)
    {
        if(g.vertexList[i].indegree == 0)
        {
        	zeroVertex.push(i);
		}
    }
    while(!zeroVertex.empty())
    {
        g.edgeNum -= divVertex(g, zeroVertex.front(), zeroVertex);
        //displayGraph(g);
        //cout << zeroVertex.size() << "front: " << zeroVertex.front() << ", back: " << zeroVertex.back() << endl;
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
        graph g = buildGraph(VERTEX_NUM, EDGE_NUM - 1, tup);
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

