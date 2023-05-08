#include <stdio.h>
#include <stdlib.h>

#define INF 99

void bellmanford(int graph[][5], int src)
{
    int n=5;
    int distance[5];
    int predec[5];

    distance[0]=predec[0]=0;

    for(int i=0;i<n;i++)
    {
        if(i!=src)
        {
            distance[i]=graph[src][i];
            predec[i]=0;
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(graph[j][i]!=INF)
            {
                if(distance[j]+graph[j][i]<distance[i])
                {
                    distance[i] = distance[j]+graph[j][i];
                    predec[i]=j;
                }
            }
        }
    }
}

int main()
{
    int graph[7][7] = {
    
        {INF ,  6  ,  5  ,  5  , INF ,  INF , INF },
        {INF , INF , INF , INF , -1  ,  INF , INF },
        {INF , -2  , INF , INF ,  1  ,  INF , INF },
        {INF , INF , -2  , INF , INF ,  -1  , INF },
        {INF , INF , INF , INF , INF ,  INF ,  3  },
        {INF , INF , INF , INF , INF ,  INF ,  3  },
        {INF , INF , INF , INF , INF ,  INF , INF }
    };

    bellmanford(graph,0);
}