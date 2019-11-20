#ifndef DG_ADJMATRIX_CPP
#define DG_ADJMATRIX_CPP

/* You need to following work before use:
 * 1. #define weightType, nullWeight, idType, VERTEX_NUM, which means VERTEX_NUM is fixed.
 * 2. typedef vertexInfo, EdgeInfo,
 *    and how to init them during construction, The initiation is done by copying a V/E Info into graph g.
 * 
 * 
 * You can see how to do it in ../exp8/ShortestPath.cpp */

typedef struct Vertex{
    vertexInfo Vinfo;
    idType ID[VERTEX_NUM];
}vertex;

typedef struct Edge{
    edgeInfo Einfo;
    weightType weightM[VERTEX_NUM][VERTEX_NUM];
}edge;

typedef struct Graph_ADJ_Matrix{
    vertex V;
    edge E;
}graph;

int getID(idType ID[], idType find)
{
    for(int i = 0; i < VERTEX_NUM; i++)
    {
        if(ID[i] == find)
        {
            return i;
        }
    }
    return -1;
}

void constructMatrix(int edgeTup[][2], weightType weight[], int edgeNum, weightType matrix[VERTEX_NUM][VERTEX_NUM])
{
    for(int i = 0; i < VERTEX_NUM; i++)
    {
        for(int j = 0; j < VERTEX_NUM; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < edgeNum; i++)
    {
        matrix[edgeTup[i][0]][edgeTup[i][1]] = weight[i];
    }
}

void ConstructID(idType ID[], idType IDlist[])
{
    for(int i = 0; i < VERTEX_NUM; i++)
    {
        ID[i] = IDlist[i];
    }
}

void constructGraph(graph &g, vertexInfo VI, idType IDlist[VERTEX_NUM], edgeInfo EI, int edgeNum, int edgeTup[][2], weightType weight[])
{
    g.V.Vinfo = VI;
    ConstructID(g.V.ID, IDlist);
    g.E.Einfo = EI;
    constructMatrix(edgeTup, weight, edgeNum, g.E.weightM);
}

bool deleteEdge(graph &g, idType from, idType to)
{
    int f = getID(g.V.ID, from), t = getID(g.V.ID, to);
    if(f == -1 || t == -1)
    {
        return false;
    }
    else
    {
        g.E.weightM[f][t] = nullWeight;
    }
}

#endif