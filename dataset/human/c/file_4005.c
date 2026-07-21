#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int main(void)
{
    int a,b,k,i,d[200],j=0;
    scanf("%d%d%d",&a,&b,&k);

    for(i=max(a,b);i>0;i--)
    {
        if(a%i == 0 && b%i == 0)
            {
                d[j] = i;
                j++;
            }
    }
        printf("%d",d[k-1]);
    return 0;
}
