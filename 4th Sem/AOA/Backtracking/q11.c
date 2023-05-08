#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

bool place(int r, int c, int board[])
{  
    for(int i=0;i<c;i++)
    {
        if(board[i]==r || (abs(board[i]-r)==abs(i-c)))
        {
            return false;
        }
    }
    return true;
}

bool nqueens(int board[],int c)
{
    if(c == N)
    {
        return true;
    }
    for(int i=0;i<N;i++)
    {
        if(place(i,c,board))
        {
            board[c]=i;
            if(nqueens(board,c+1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int board[N];
    
    if(nqueens(board,0))
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(board[j]==i)
                {
                    printf("Q ");
                }
                else
                {
                    printf(". ");
                }
            }
            printf("\n\n");
        }
    }
    return 0;
}
