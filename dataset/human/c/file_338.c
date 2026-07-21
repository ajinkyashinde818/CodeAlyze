#include<stdio.h>
int main()
{
    int N,R;
    int Inner;
    scanf("%d", &N);
    scanf("%d", &R);
    if(N<10)
    {
        Inner = R + (100*(10-N));
        printf("%d\n", Inner);
    }
    else
    {
        Inner = R;
        printf("%d\n", Inner);
    }

    return 0;
}
