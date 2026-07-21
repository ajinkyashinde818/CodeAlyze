#include<stdio.h>
#include<string.h>
#define S 100
int main()
{
    int A,B,C,m,n;
    scanf("%d %d %d",&A,&B,&C);
    if(A+B<C)
    {
        m=A+B+B+1;
        printf("%d\n",m);
    }
    else
    {
        n=B+C;
        printf("%d",n);
    }

    return 0;


}
