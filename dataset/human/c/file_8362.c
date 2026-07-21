#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N,K;
    scanf("%d",&N);
    char S[N];
    scanf("%s",S);
    scanf("%d",&K);
    char tmp=S[K-1];
    for (size_t i = 0; i < N; i++)
    {
        if (S[i]!=tmp)
        {
            S[i]='*';
        }
    }
    printf("%s\n",S);
    return 0;
}
