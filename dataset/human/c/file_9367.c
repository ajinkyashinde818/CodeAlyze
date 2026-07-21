#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,d,a[100],b,i,sum=0;
    scanf("%d %d %d",&n,&d,&b);
    d=d-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=d/a[i]+1;
        sum=sum+a[i];
    }
    printf("%d",sum+b);
    return 0;
}
