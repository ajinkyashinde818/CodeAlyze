#include<stdio.h>
int main()
{
    int A,B,C,D,sum=1,sum2=1;
    scanf("%d%d%d%d",&A,&B,&C,&D);
    sum=A*B;
    sum2=C*D;
    if(sum >= sum2)
        printf("%d\n",sum);
    else
        printf("%d\n",sum2);

    return 0;
}
