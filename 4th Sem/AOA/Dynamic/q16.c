#include <stdio.h>
#include <stdlib.h>

#define INF 99

void apsp(int A[][3], int n)
{
    int W[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            W[i][j]=A[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(W[j][i]+W[i][k]<W[j][k])
                {
                    W[j][k]= W[j][i]+W[i][k];
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("[ ");
        for(int j=0;j<n;j++)
        {
            printf("%d | ",W[i][j]);
        }
        printf("]\n");
    }
}

int main()
{
    int n=3;
    int graph[3][3]={
                    {0,4,11},
                    {6,0,2},
                    {3,INF,0}
                    };

    apsp(graph,n);
}