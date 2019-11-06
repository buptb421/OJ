#include <stdio.h>
#include <new>

#define LEN 100
#define nullptr NULL

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

//begin{DEBUG}
/*
void mygets(char s[], int n)// n = 0, 1, 2, 3, 4, 5
{
    char a[6][LEN] = {
        "1,0,1,2,1,3,1,4,2,0,2,1,2,3,",
        "0,1,0,3,1,4,2,0,2,1,3,2,4,1,",
        "2,1,1,2,",
        "1,4,3,2,2,0,0,1,2,4,",
        "2,3,2,4,2,0,2,1,",
        "0,3,2,3,4,3,1,3,"
    };
    for(int i = 0; i < LEN; i++)
    {
        s[i] = a[n][i];
    }
}
void displayPNode_pos(OLNode *n)
{
    if(n == nullptr)
    {
        printf("[N][N]");
    }
    else
    {
        printf("[%d][%d]", n->pos[0], n->pos[1]);
    }
    
}
void displayPNode(OLNode *n)
{
    if(n == nullptr)
    {
        printf("(weight :N, pos[N][N], next([N][N], [N][N]))");
    }
    else
    {
        printf("(weight :%d, pos", n->weight, n->pos[0], n->pos[1]);
        displayPNode_pos(n);
        printf(", next(");
        displayPNode_pos(n->next[0]);
        displayPNode_pos(n->next[1]);
        printf("))");
    }
}
void displayHead(OLHead h)
{
    printf("ID :%d, ", h.ID);
    for(int index = 0; index < 2; index++)
    {
        printf("[%d](num: %d, ptr to: (", index, h.num[index]);
        displayPNode_pos(h.ptr[index]);
        printf(")");
        if(index == 0)
        {
            printf(", ");
        }
    }
}
void displayHeadList(digraph g)
{
    printf("HEAD(%d vertex)\n{", g.vertexNum);
    for(int i = 0; i < g.vertexNum; i++)
    {
        printf("\n  ");
        displayHead(g.head[i]);
    }
    printf("\n}\n");
}
void displayNodeList(digraph g)
{
    printf("NODE(%d edge)\n{", g.edgeNum);
    for(int i = 0; i < g.edgeNum; i++)
    {
        printf("\n  ");
        displayPNode(g.node + i);
    }
    printf("\n}\n");
}
void displayGraph_list(digraph g)
{
    displayHeadList(g);
    displayNodeList(g);
}
OLNode *accessPos(digraph g, int x, int y)// to be continue
{
    if(x >= g.vertexNum || x < 0 || y >= g.vertexNum || y < 0)
    {
        return nullptr;
    }
    else
    {
        return nullptr;
    }
    
}
void displayMatrix(digraph g)// to be continue
{

}
*/
//end{DEBUG}

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
    while(!(*pnext == nullptr || nowPos >= node->pos[1 - index]))
    {
        nowPos = (*pnext)->pos[1 - index];
        if((*pnext)->pos[1 - index] < node->pos[1 - index])
        {
            pnext = &(*pnext)->next[index];
        }
        else if((*pnext)->pos[1 - index] > node->pos[1 - index])
        {
            node->next[index] = *pnext;
        }
    }
    if(nowPos != node->pos[1 - index])
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
    
    newGraph.head = constructOLHead_list(n);
    if(newGraph.head == nullptr)
    {
        printf("Memory overflow when constructing head.\n");
    }
    else
    {
        newGraph.node = constructOLNode_list(m, tup);
        if(newGraph.node == nullptr)
        {
            delete[] newGraph.head;
            newGraph.head = nullptr;
            printf("Memory overflow when constructing node.\n");
        }
        else
        {
            newGraph.vertexNum = n;
            newGraph.edgeNum = m;
            for(int i = 0; i < m; i++)
            {
                insertOLNode(newGraph.head, newGraph.node + i);
            }
        }
    }
    return newGraph;
}

void dianzan(digraph g)
{
    int count;
    OLNode *prev;
    for(int i = 0; i < g.vertexNum; i++)
    {
        count = 0;
        prev = g.head[i].ptr[0];
        while(prev != nullptr)
        {
            count++;
            prev->weight += count % 2;
            prev = prev->next[0];
        }
    }
}

void displayDianzan(digraph g, int a)
{
    int count = 0;
    OLNode *prev = g.head[a].ptr[1];

    while(prev != nullptr)
    {
        if(prev->weight > 0)
        {
            count++;
            printf("%d,", prev->pos[0]);
        }
        prev = prev->next[1];
    }
    if(count == 0)
    {
        printf("-1");
    }
    
}

int get2tuple(char s[], int tup[][2]) //return m, which is the number of edges.
{
    int n = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            tup[n / 2][n % 2] = s[i] - '0';
            n++;
        }
    }
    return n / 2;
}

int main()
{
	char s[LEN];
    int tup[LEN / 4][2];
    //mygets(s, 4);
    gets(s);
    
    int m = get2tuple(s, tup);
    digraph g = constructGraph(5, m, tup);
    //displayGraph_list(g);
    dianzan(g);
    //displayGraph_list(g);
    
    int a;
    scanf("%d", &a);
    displayDianzan(g, a);
    
    return 0;
}

