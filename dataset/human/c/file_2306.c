#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int limit=1e9;
    int n,k,s,temp;
    scanf("%d %d %d",&n,&k,&s);
    if(s==limit)
        temp=limit-1;
    else
        temp=limit;
    while(n>0)
    {
        n--;
        if(k>0)
        {
            k--;
            printf("%d ",s);
        }
        else
            printf("%d ",temp);
    }
    return 0;
}
