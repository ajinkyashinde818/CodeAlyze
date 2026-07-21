#include<bits/stdc++.h>
using namespace std;

int N,M;
char temp[100][100] = {0},temp2[100][100] = {0};

int main()
{
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf(" %c",&temp[i][j]);
        }
    }
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf(" %c",&temp2[i][j]);
        }
    }
    for(int i = 0; i <= N - M; i++)
    {
        for(int j = 0; j <= N - M; j++)
        {
            bool flag = true;
            for(int k = 0; k < M; k++)
            {
                for(int l = 0; l < M; l++)
                {
                    if(temp[i + k][j + l] != temp2[k][l])flag = false;
                }
            }
            if(flag)
            {
                printf("Yes\n");
                return 0;
            }
        }
    }
    printf("No\n");
    return 0;
}
