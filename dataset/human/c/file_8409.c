#include<stdio.h>
#include<stdio.h>
int main()
{
    char S[10];
    int N,K;
    scanf("%d%s%d",&N,S,&K);
    char ch;
    ch = S[K-1];
    int i;
    for(i=0; i<N; i++)
    {
        if(S[i] == ch)
        {
            printf("%c",S[i]);
        }
        else
        {
            printf("*");
        }
    }
    return 0;
}
