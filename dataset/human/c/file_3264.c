#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long ll;

int hikaku(const void *n1,const void *n2)
{
    return *(int*)n1-*(int*)n2;
}

int main()
{

    int k,n;
    scanf("%d %d",&k,&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    qsort(a,n,sizeof(int),hikaku);
    int tobasu=0;
    for(int i=0;i<n-1;i++)
    {
        tobasu=fmax(a[i+1]-a[i],tobasu);
    }
    tobasu=fmax(tobasu,k-a[n-1]+a[0]);

    printf("%d\n",k-tobasu);

    return 0;
}
