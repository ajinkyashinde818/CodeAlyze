#include<stdio.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
int n,r[200005],i,_max,_min;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&r[i]);
    _max=r[2]-r[1];
    _min=r[1];
    for(i=2;i<=n;i++)
    {
        _max=max(r[i]-_min,_max);
        _min=min(r[i],_min);
    }
    printf("%d\n",_max);
    return 0;
}
