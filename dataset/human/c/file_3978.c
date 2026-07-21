#include<stdio.h>
int main()
{
    int a,b,k,i,count=0,d;
    int s[100];
    scanf("%d %d %d",&a,&b,&k);
    for(i=1;i<=a || i<=b;i++)
    {
        if(a%i==0 && b%i==0)
        {
            s[count]=i;
            count++;
        }
    }
    printf("%d\n",s[count-k]);
    return 0;
}
