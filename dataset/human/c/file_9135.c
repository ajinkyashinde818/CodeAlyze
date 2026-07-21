#include <stdio.h>

int main()
{
    int N,K,result = 0;
    int h[100000];
    scanf("%d %d",&N,&K);
    for(int i = 0;i < N;i++)scanf("%d",&h[i]);
    for (int i = 0; i < N; i++)if(h[i] >= K)result++;
    printf("%d",result);
    return 0;
}
