#include<stdio.h>
int main()
{
    long long int A,B,X,Y,Num_snack;
    scanf("%lld%lld",&A,&B);
    if(A>B)
    {
        X=A;
    }
    else
    {
        X=B;
    }
    for(;X>=1;X--)
    {
        if(A%X==0&&B%X==0)
        {
            Y=X;
            break;
        }
    }
    Num_snack=(A*B)/Y;
    printf("%lld\n",Num_snack);
    return 0;
}
