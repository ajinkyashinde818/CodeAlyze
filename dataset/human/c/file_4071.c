#include<stdio.h>
int main()
{
    int A,B,K,count=0,c,i;

    scanf("%d%d%d",&A,&B,&K);
    for(i=A;count<K;i--)
    {
        if(A%i==0 && B%i==0)
        {
            count++;
            c = i;
        }
    }
    printf("%d",c);
    return 0;

}
