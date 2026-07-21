#include<stdio.h>
int main(void)
{
    int N,K,h[100000],b=0;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&h[i]);
        if(K<=h[i]){
            b=b+1;
        }
    }
    printf("%d\n",b);
    return 0;
}
