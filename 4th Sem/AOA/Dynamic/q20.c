#include <stdio.h>
#include <stdlib.h>
#define INF 99

void multistage(int n, int cost[], int fgraph[][n], int path[])
{
    for(int i=n-2;i>=0;i--)
    {
        cost[i]=INF;
        for(int j=0;j<n;j++)
        {
            if(fgraph[i][j]!=-1)
            {
                if(cost[i]>cost[j]+fgraph[i][j])
                {
                    cost[i] = cost[j] + fgraph[i][j];
                    path[i] = j;
                }
            }
        }
    }

    printf("The final cost is %d.\n",cost[0]);
    printf("The minimum-cost path is: ");
    int vertex = 0;
    printf("%d", vertex+1);
    while (vertex != n-1) 
    {
        vertex = path[vertex];
        printf("-%d", vertex+1);
    }
    printf("\n");
}

int main()
{
    int fgraph[9][9]={
                   //  0     1     2     3     4     5     6     7     8   
                    { -1  ,  5  ,  2  , -1  , -1  , -1  , -1  , -1  , -1  },//0
                    { -1  , -1  , -1  ,   3 , -1  ,  3  , -1  , -1  , -1  },//1
                    { -1  , -1  , -1  ,   6 ,  5  ,  8  , -1  , -1  , -1  },//2 
                    { -1  , -1  , -1  ,  -1 , -1  , -1  ,  1  ,  6  , -1  },//3
                    { -1  , -1  , -1  ,  -1 , -1  , -1  ,  6  ,  2  , -1  },//4
                    { -1  , -1  , -1  ,  -1 , -1  , -1  , -1  ,  2  , -1  },//5
                    { -1  , -1  , -1  ,  -1 , -1  , -1  , -1  , -1  ,  7  },//6
                    { -1  , -1  , -1  ,  -1 , -1  , -1  , -1  , -1  ,  3  },//7
                    { -1  , -1  , -1  ,  -1 , -1  , -1  , -1  , -1  , -1  } //8
                    };
    
    int n=9;
    int cost[n];
    int path[n];
    cost[n-1]=0;
    multistage(n,cost,fgraph,path);
    
    return 0;
}
