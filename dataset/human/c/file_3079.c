#include <stdio.h>
#include <stdlib.h>

int asc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main()
{
    int k,n,a[200000];

    scanf("%d %d",&k,&n);

    int i,j;

    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    qsort(a,n,sizeof(int),asc);

    long long ans = 0,max = 0;
    for (i = 0; i < n - 1; i++)
    {
        if(a[i + 1] - a[i] > max)max = a[i + 1] - a[i];
    }
    if(k - a[n - 1] + a[0] > max)max = k - a[n - 1] + a[0] ;

    printf("%lld",k - max);
}
