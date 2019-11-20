#include <iostream>
#include <stack>
using namespace std;

constexpr int VERTEX_NUM = 7;
constexpr int EDGE_NUM = 12;

int connect_edge[EDGE_NUM][2] = {
    {1, 2, },
    {1, 4, },
    {2, 4, },
    {2, 5, },
    {3, 1, },
    {3, 6, },
    {4, 3, },
    {4, 5, },
    {4, 6, },
    {4, 7, },
    {5, 7, },
    {7, 6, },
};

int weight_edge[EDGE_NUM] = {
    2, 1, 3, 10, 4, 5, 2, 2, 8, 4, 6, 1,
};

typedef struct Graph_ADJ_Matrix{
    int vn;
    int en;
    int m[VERTEX_NUM][VERTEX_NUM];
}graph;

typedef struct dijkstra_vertex_trace
{
    int dist;
    int prev;
    int heapPos;
}vertex;

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
        g.m[connect_edge[i][0] - 1][connect_edge[i][1] - 1] = weight_edge[i];
    }
}

void displayGraph(graph g)
{
    for(int i = 0; i < g.vn; i++)
    {
        for(int j = 0; j < g.vn; j++)
        {
            cout << g.m[i][j] << ", ";
        }
        cout << endl;
    }
}

void displayVertex(vertex vtx[], int i)
{
     cout << "id: " << i + 1 << ", info: (dist: " << vtx[i].dist << ", prev id: " << vtx[i].prev + 1 << ", head pos in: " << vtx[i].heapPos << ')';

}

void displyHeap(int heap[], int heapSize, vertex vtx[])
{
    int floor[] = {1, 2, 2, 3, 3, 3, 3};
    cout << "----------" << endl;

    cout << "Certain{" << endl;
    for(int i = 0; i < VERTEX_NUM; i++)
    {
        if(vtx[i].heapPos == VERTEX_NUM)
        {
            cout << "  ";
            displayVertex(vtx, i);
            cout << endl;
        }
    }
    cout << '}' << endl;

    cout << "In heap{" << endl;
    for(int i = 0; i < heapSize; i++)
    {
        cout << "  [heap pos: " << i << ", ";
        displayVertex(vtx, heap[i]);
        cout << ']' << endl;
    }
    cout << '}' << endl;

    cout << "Unused{" << endl;
    for(int i = 0; i < VERTEX_NUM; i++)
    {
        if(vtx[i].heapPos == -1)
        {
            cout << "  ";
            displayVertex(vtx, i);
            cout << endl;
        }
    }
    cout << '}' << endl;

    cout << "----------" << endl;
}

// Heap operations
int c2p(int c) // children to parent
{
    return (c - 1) / 2;
}

int p2l(int p) // parent to left
{
    return 2 * p + 1;
}

int p2r(int p) // parent to right
{
    return 2 * p + 2;
}

void heap_exchange(int h[], vertex v[], int m, int n)
{
    int temp = h[m];
    h[m] = h[n];
    h[n] = temp;

    v[h[m]].heapPos = m;
    v[h[n]].heapPos = n;
}

bool heap_shiftup(int h[], vertex v[], int &n)
{
    int p = c2p(n);
    if(n > 0)
    {
        heap_exchange(h, v, n, p);
        n = p;
        return true;
    }
    else return false;
}

bool heap_shiftdown(int h[], int heapSize, vertex v[], int &n)
{
    int l = p2l(n);
    if(l < heapSize && v[h[l]].dist < v[h[l + 1]].dist)
    {
        heap_exchange(h, v, n, l);
        n = l;
    }
    else if(l + 1 < heapSize)
    {
        heap_exchange(h, v, n, l + 1);
        n = l + 1;
    }
    else return false;
    return true;
}

void heap_refresh(int h[], int heapSize, vertex v[], int n)
{
    int balance = 0, lc = -1, next;
    bool ensuite = true;
    do{
        if(balance > 0)
        {
            ensuite = heap_shiftup(h, v, n);
        }
        else if(balance < 0)
        {
            ensuite = heap_shiftdown(h, heapSize, v, n);
        }

        if(n > 0 && v[h[n]].dist < v[h[c2p(n)]].dist)
        {
            balance = 1;
        }
        else 
        {
            lc = p2l(n);
            if((lc < heapSize && v[h[lc]].dist < v[h[n]].dist) || ((lc + 1) < heapSize && v[h[lc + 1]].dist < v[h[n]].dist))
            {
                balance = -1;
            }
            else
            {
                balance = 0;
            }
        }
    }while(balance != 0 && ensuite);
}

int heap_pop_top(int h[], int &heapSize, vertex v[])
{
    heapSize--;
    heap_exchange(h, v, 0, heapSize);
    heap_refresh(h, heapSize, v, 0);
    v[h[heapSize]].heapPos = VERTEX_NUM;
    return h[heapSize];
}

void heap_insert(int h[], int &heapSize, vertex v[], int vID)
{
    h[heapSize] = vID;
    v[vID].heapPos = heapSize;
    heapSize++;
    heap_refresh(h, heapSize, v, heapSize - 1);
}

void dijkstra(graph g, vertex vtx[], int s)
{
    int minHeap[VERTEX_NUM];
    int heapSize = 0;
    int nowCertain;
    for(int i = 0 ; i < VERTEX_NUM; i++)
    {
        vtx[i].dist = -1;
        vtx[i].prev = -1;
        vtx[i].heapPos = -1;
    }// init vertex
    
    vtx[s].dist = 0;
    heap_insert(minHeap, heapSize, vtx, s);

    while(heapSize > 0)
    {
        
    	cout << "Pop[";
        displayVertex(vtx, minHeap[0]);
        cout << ']' << endl;
        
        nowCertain = heap_pop_top(minHeap, heapSize, vtx);
        displyHeap(minHeap, heapSize, vtx);

        for(int j = 0; j < VERTEX_NUM; j++)
        {
            if(g.m[nowCertain][j] > 0)
            {
                if(vtx[j].dist == -1)
                {
                    vtx[j].dist = vtx[nowCertain].dist + g.m[nowCertain][j];
                    vtx[j].prev = nowCertain;
                    
                    cout << "Insert[";
                    displayVertex(vtx, j);
                    cout << ']' << endl;
                    
                    heap_insert(minHeap, heapSize, vtx, j);
                    displyHeap(minHeap, heapSize, vtx);
                }
                else if(vtx[j].heapPos != VERTEX_NUM && vtx[nowCertain].dist + g.m[nowCertain][j] < vtx[j].dist)
                {
                    vtx[j].dist = vtx[nowCertain].dist + g.m[nowCertain][j];
                    vtx[j].prev = nowCertain;
                    
                    cout << "refresh[";
                    displayVertex(vtx, j);
                    cout << ']' << endl;
                    
                    heap_refresh(minHeap, heapSize, vtx, vtx[j].heapPos);
                    displyHeap(minHeap, heapSize, vtx);
                }
            }
        }
    }
    
}

int main()
{
    graph g;
    getGraph(g);
    //displayGraph(g);

    char comma;
    int f, t;
    cin >> f >> comma >> t;
    cout << f << ' ' << t << endl;
    g.en--;
    g.m[f - 1][t - 1] = 0;

    //displayGraph(g);

    vertex v[VERTEX_NUM];
    dijkstra(g, v, 1 - 1);

    int trace = 6 - 1;
    stack<int> traceID;
    while(trace != -1)
    {
        traceID.push(trace + 1);
        trace = v[trace].prev;
    }

    while(!traceID.empty())
    {
        cout << traceID.top() << ',';
        traceID.pop();
    }

    return 0;
}
