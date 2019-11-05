#include <stdio.h>
#include <new>

#define LEN 100

typedef struct ORTHOGONAL_LIST_NODE{
    int weight;
    int pos[2];
    struct ORTHOGONAL_LIST_NODE *next[2];
}OLNode;

typedef struct ORTHOGONAL_LIST_HEAD{
    int ID;
    int num[2];
    OLNode *ptr[2];
}OLHead;

typedef struct Digraph{
    int vertexNum, edgeNum;
    OLHead *head;// a list of heads, which represent the spare matrix of the graph.
    OLNode *node;// a list of nodes, which healp with memory management.
}digraph;

OLHead *constructOLHead_list(int n)
{
    OLHead *p = new OLHead[n];
    if(p == nullptr)
    {
        printf("Memory overflow when construct head list.\n");
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            p[i].ID = i;
            for(int index = 0; index < 2; index++)
            {
                p[i].num[index] = 0;
                p[i].ptr[index] = nullptr;
            }
        }
    }
    return p;
}

OLNode *constructOLNode_list(int m, int tup[][2])
{
    OLNode *p = new OLNode[m];
    if(p == nullptr)
    {
        printf("Memory overflow when construct node.\n");
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            for(int index = 0; index < 2; index++)
            {
                p[i].pos[index] = tup[i][index];
                p[i].next[index] = nullptr;
            }
            p[i].weight = 0;
        }
    }
    return p;
}

void insertOLNode_index(OLHead head[], OLNode *node, int index)
{
    head += node->pos[index];

    head->num[index]++;
    OLNode **pnext = &head->ptr[index];
    int nowPos = -1;
    while(!(*pnext == nullptr || nowPos >= node->pos[index]))
    {
        nowPos = (*pnext)->pos[index];
        if((*pnext)->pos[index] < node->pos[index])
        {
            pnext = &(*pnext)->next[index];
        }
        else if((*pnext)->pos[index] > node->pos[index])
        {
            node->next[index] = (*pnext)->next[index];
        }
    }
    if(nowPos != node->pos[index])
    {
        *pnext = node;
    }
}

void insertOLNode(OLHead head[], OLNode *node)
{
    for(int index = 0; index < 2; index++)
    {
        insertOLNode_index(head, node, index);
    }
}

digraph constructGraph(int n, int m, int tup[][2])
{
    digraph newGraph;
    newGraph.vertexNum = n;
    newGraph.edgeNum = m;
    newGraph.head = constructOLHead_list(n);
    newGraph.node = constructOLNode_list(m, tup);

    if(newGraph.head != nullptr && newGraph.node != nullptr)
    {
        for(int i = 0; i < m; i++)
        {
            insertOLNode(newGraph.head, newGraph.node + i);
        }
    }
    else
    {
        printf("The construction of graph failed.\n");
    }
    
    return newGraph;
}

int get2tuple(int tup[][2]) //return m, which is the number of edges.
{
    char s[LEN];
    gets(s);
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {
        
    }
}

