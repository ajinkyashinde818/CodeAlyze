#include<stdio.h>
int main()
{
    int N,R,I;

    while ((N<1||100<N)||(R<0||4111<R))
    {
        scanf("%d %d\n",&N,&R);
    }

    if (N<10)
    {
        I=R+100*(10-N);
    }else
    {
        I=R;
    }

    printf("%d\n",I);

    return 0;
}
