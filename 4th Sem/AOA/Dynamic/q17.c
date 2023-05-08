#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 999

int mcp(int p[])
{
    int n = 5 - 1;
    int M[n][n];
    for(int i=0;i<n;i++)
    {
        M[i][i]=0;
    }

    for(int L=2;L<=n;L++)
    {
        for(int i=0;i<n-L+1;i++)
        {
            int j=i+L-1;
            M[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q = M[i][k] + M[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(q<M[i][j])
                {
                    M[i][j]=q;
                }
            }
        }
    }
    return M[0][n-1];
}

int main()
{
    int array[5]={5,4,6,2,7};
    int min_mult = mcp(array);

    printf("Minimum number of scalar multiplications: %d\n", min_mult);
}