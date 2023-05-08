#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 99

int min_dist(int distance[], bool visited[], int n, int cost[][5], int v)
{
    int min = INF;
    int min_index = -1;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && distance[i] < min)
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void shortestpath(int v, int cost[][5], int n)
{
    int dist[n];
    bool s[n];

    for(int i = 0; i < n; i++)
    {
        s[i] = false;
        dist[i] = INF;
    }

    s[v] = true;
    dist[v] = 0;

    for(int i = 1; i < n - 1; i++)
    {
        int u = min_dist(dist, s, n, cost, v);
        s[u] = true;
        for(int j = 0; j < n; j++)
        {
            if(!s[j] && dist[u] + cost[u][j] < dist[j] && dist[u]!=INF)
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    for(int i = 0; i < n; i++) 
    {
        printf("\nDistance from %d to %d is %d.", v, i, dist[i]);
    }
}


int main()
{
    int graph[5][5] = {
        {0, 10, 5, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 3, 0, 9, 2},
        {0, 0, 0, 0, 0},
        {2, 0, 0, 6, 0}
    };

    shortestpath(0, graph, 5);
}
