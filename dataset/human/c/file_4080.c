#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,k,i,max,count=0,m;
    scanf("%d %d %d",&a,&b,&k);
    if(a>=b)
    {
        max = a;
    }else{
        max = b;
    }
    for(i=max;i>=1;i--)
    {
        if(a%i==0 && b%i==0)
        {
            count++;
        }
        if(count == k)
        {
            m = i;
            break;
        }
    }

    printf("%d\n",m);
    return 0;
}
