/*
int initial_edge[EDGE_NUM][2] = {
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

int ID[VERTEX_NUM] = {
    1, 2, 3, 4, 5, 6, 7,
};
*/
/* This programe need file ../GraphAlgor/BFS_*.cpp and ../GraphAlgor/DG_*.cpp, which means you need
 * to substitude #include<XXX> into content in desired file.
 * The choice is of variaty, plus your personal modifacation should be safe enough.
 */

#include <iostream>
#include <new>
using namespace std;

// notice INIT_EDGE_NUM is not necessary for other file, it only works locally.
#define INIT_EDGE_NUM 12

#define VERTEX_NUM 7
#define nullWeight 0
typedef struct VERTEX_INFO{
    int num;
    int prev[VERTEX_NUM]; // previous vertex
    int dist[VERTEX_NUM]; // distance from designated vertex
}vertexInfo;

typedef int edgeInfo; // in certain conditions would be typedef struct XXX{ }YYY;

// idType, weightType are type, just like elemType. 
#define weightType int
#define idType int

#include "../GraphAlgor/DG_AdjMatrix.cpp"
//#include "../GraphAlgor/BFS.cpp"

void dijkstra(graph &g, int strart, int end)// use of reference to g here is cutting off copy if you use Adj matrix. If you use Adj LL, delete '&'.
{
    // we claime -1 to be $+ \infty$ since all weight are positive.
}

int main()
{
    int initial_edge[INIT_EDGE_NUM][2] = {
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

    int weight_edge[INIT_EDGE_NUM] = {
        2, 1, 3, 10, 4, 5, 2, 2, 8, 4, 6, 1,
    };

    int ID[VERTEX_NUM] = {
        1, 2, 3, 4, 5, 6, 7,
    };

    graph g;

    vertexInfo tempVI ={
        VERTEX_NUM,
        {-1, -1, -1, -1, -1, -1, -1, },
        {-1, -1, -1, -1, -1, -1, -1, },
    };

    constructGraph(g, tempVI, ID, INIT_EDGE_NUM, INIT_EDGE_NUM, initial_edge, weight_edge);

    int from, to;
    cin >> from >> to;
    if(deleteEdge(g, from, to))

    dijkstra(g, 0, 5);// v1 is 0, v6 is 5

    return 0;
}
