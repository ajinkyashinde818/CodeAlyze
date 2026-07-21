#include<stdio.h>

int main()
{
    int N,K,i,h,a=0;
    int polje[100000];
    scanf("%d", &N);
    scanf("%d", &K);
    for(i=0;i<N;i++)
        scanf("%d", &polje[i]);
    for(i=0;i<N;i++)
    {
        if(polje[i]>=K)
            a=a+1;
    }
    printf("%d", a);           
    return 0;
}
