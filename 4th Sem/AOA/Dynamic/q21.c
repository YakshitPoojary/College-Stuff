#include <stdio.h>
#include <stdlib.h>
#define INF 99

void multistage(int n, int cost[], int bgraph[][n], int path[])
{
    for(int i=1;i<n;i++)
    {
        cost[i]=INF;
        for(int j=0;j<n;j++)
        {
            if(bgraph[i][j]!=-1)
            {
                if(cost[i]>cost[j]+bgraph[i][j])
                {
                    cost[i] = cost[j] + bgraph[i][j];
                    path[i] = j;
                }
            }
        }
    }

    printf("The final cost is %d.\n",cost[8]);
    printf("The minimum-cost path is: ");
    int vertex = 8;
    printf("%d", vertex+1);
    while (vertex != 0) 
    {
        vertex = path[vertex];
        printf("-%d", vertex+1);
    }
    printf("\n");
}

int main()
{
    int bgraph[9][9]={
                   //  0     1     2     3     4     5     6     7     8   
                    {  0  , -1  , -1  , -1  , -1  , -1  , -1  , -1  , -1  },//0
                    {  5  ,  0  , -1  , -1  , -1  , -1  , -1  , -1  , -1  },//1
                    {  2  , -1  ,  0  , -1  , -1  , -1  , -1  , -1  , -1  },//2 
                    { -1  ,  3  ,  6  ,  0  , -1  , -1  , -1  , -1  , -1  },//3
                    { -1  , -1  ,  5  , -1  ,  0  , -1  , -1  , -1  , -1  },//4
                    { -1  ,  3  ,  8  , -1  , -1  ,  0  , -1  , -1  , -1  },//5
                    { -1  , -1  , -1  , -1  ,  6  , -1  ,  0  , -1  , -1  },//6
                    { -1  , -1  , -1  ,  6  ,  2  ,  2  , -1  ,  0  , -1  },//7
                    { -1  , -1  , -1  , -1  , -1  , -1  ,  7  ,  3  ,  0  } //8
                    };
    
    int n=9;
    int cost[n];
    int path[n];
    cost[0]=0;
    multistage(n,cost,bgraph,path);
    
    return 0;
}
