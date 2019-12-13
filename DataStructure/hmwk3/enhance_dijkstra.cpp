void dijkstra(graph g, vertex vtx[], int s)
{
    int minHeap[VERTEX_NUM];
    int heapSize = 0;
    int nowCertain;
    for (int i = 0; i < VERTEX_NUM; i++)
    {
        vtx[i].dist = -1;
        vtx[i].prev = -1;
        vtx[i].heapPos = -1;
    } // init vertex

    vtx[s].dist = 0;
    heap_insert(minHeap, heapSize, vtx, s);

    while (heapSize > 0)
    {
        nowCertain = heap_pop_top(minHeap, heapSize, vtx);

        for (int j = 0; j < VERTEX_NUM; j++)
        {
            if (g.m[nowCertain][j] > 0)
            {
                if (vtx[j].dist == -1)
                {
                    vtx[j].dist = vtx[nowCertain].dist + g.m[nowCertain][j];
                    vtx[j].prev = nowCertain;
                    heap_insert(minHeap, heapSize, vtx, j);
                }
                else if (vtx[j].heapPos != VERTEX_NUM && vtx[nowCertain].dist + g.m[nowCertain][j] < vtx[j].dist)
                {
                    vtx[j].dist = vtx[nowCertain].dist + g.m[nowCertain][j];
                    vtx[j].prev = nowCertain;
                    heap_refresh(minHeap, heapSize, vtx, vtx[j].heapPos);
                }
            }
        }
    }
}

void Dijkstra(Table T)
{ /* T is initialized in next slide*/
    Vertex V, W;
    for (;;)
    {
        V = unknown vertex with the smallest distance;
        if (V == NotAVertex)
        {
            break;
        }
        T[V].Known = true;
        for (each W adjacent to V)
        {
            if (!T[W].Known)
            {
                if (T[V].Dist + Cvw < T[W].Dist)
                {
                    Decrease(T[W].Dist to T[V].Dist + Cvw);

                    T[W].path = V;
                    T[W].edgeCount = T[V].edgeCount + 1;
                }
                else if(T[V].Dist + Cvw == T[W].Dist)
                {
                    if(T[W].edgeCount > T[V].edgeCount + 1)
                    {
                        T[W].path = V;
                        Decrease(T[W].edgeCount to T[V].edgeCount + 1);
                    }
                }
                 /* end-if update W */
            }    
        }
    } /* end-for( ; ; ) */
}