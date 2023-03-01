#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void shortest_path(int cost[][], int dist[], bool visited[][], int start, int calc, int j)
{
    int s=start-1;

    int min_d=99999,min_v=s;

    int dist_size=sizeof(dist)/sizeof(dist[0]);

    for(int i=0;i<dist_size;i++)
    {
        if(cost[s][i]!=-1 && (dist[s]+cost[s][i])<dist[i] && !visited[i])
        {
            dist[i]=dist[s]+cost[s][i];
            if(min_d>dist[i])
            {
                min_d=dist[i];
                min_v=i+1;
            }
        }
    }

    
    calc[j][0]=start;
    for(int i=1;i<(dist_size+1);i++)
    {
        calc[j][i]=dist[i-1];
    }
    visited[s]=true;
    if(isVisited(visited))
    {
        return;
    }
    else
    {
        shortest_path(cost,dist,visited,min_v,calc,++j);
    }
}

int main()
{
    int n;
    printf("Enter number of vertex: ");
    scanf("%d",&n);

    int cost_arr[n][n];
    int dist_arr[n];
    bool visited_arr[n];
    int calc[n][n+1];

    for(int i=0;i<n;i++)
    {
        printf("\n\n");
        for(int j=0;j<n;j++)
        {
            int c;
            printf("Enter cost between %d and %d(-1 if no path): ",(i+1),(j+1));
            scanf("%d",&c);
            cost_arr[i][j]=c;
        }
    }

    int st;
    printf("Enter the starting vertex");
    scanf("%d",&st);

    shortest_path(cost_arr,dist_arr,visited_arr, st, calc,0);

    // printf("The adjacency matrix is: \n\n");

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         printf(" %d ",cost[i][j]);
    //     }
    //     printf("\n");
    // }
}