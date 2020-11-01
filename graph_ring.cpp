/*
 * find all rings in undirected graph
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int father[MAX_NODES];
int max_node;

struct Edge
{
    int s;
    int e;
    int w;
};

Edge edges[] =
{
    {5, 6, 1},
    {0, 1, 3},
    {0, 4, 1},
    {4, 3, 1},
    {3, 1, 8},
    {1, 2, 1},
    {3, 2, 2}
};

void display_ring(int s, int e)
{
    int tmp = s;

    printf("find a ring %d --> ", e);

    while(tmp != e) {
        printf("%d --> ", tmp);
        tmp = father[tmp];
    }
    cout << e << endl;
}

void display_graph(void)
{
    int i, j;

    cout << "  ";
    for(j=0; j<max_node; j++)
        printf(" %2d", j);
    cout << endl;

    for(i=0; i<max_node; i++) {
        printf("%2d", i);
        for(j=0; j<max_node; j++)
            printf(" %2d", graph[i][j]);
        cout << endl;
    }
}

void display_edges(void)
{
    int i;

    for(i=0; i<sizeof(edges)/sizeof(edges[0]); i++)
        printf("%2d <--> %2d weight %d\n",
            edges[i].s, edges[i].e, edges[i].w);
}

void dfs(int s)
{
    int i;

    visited[s] = 1;
    for(i=0; i<max_node; i++) {
        /* if s connected with i */
        if (graph[s][i] != 0) {
            if (visited[i] == 0) {
                father[i] = s;
                dfs(i);
            } else if (visited[i] == 1 && i != father[s]) {
                display_ring(s, i);
            }
        }
    }
    visited[s] = 2;
}

int main(void)
{
    int i;

    display_edges();

    max_node = 0;
    for(i=0; i<sizeof(edges)/sizeof(edges[0]); i++) {
        graph[edges[i].s][edges[i].e] = edges[i].w;
        graph[edges[i].e][edges[i].s] = edges[i].w;
        
        max_node = max(max(edges[i].s, edges[i].e), max_node);
    }
    max_node++;

    display_graph();

    for(i=0; i<max_node; i++)
        if(visited[i] == 0)
            dfs(i);

    return 0;
}
