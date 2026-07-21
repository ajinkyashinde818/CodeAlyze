#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int n,i;
    long a,t[200000],m=LONG_MAX;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld",&a);
        t[i]=a;
        if(0<i)t[i]+=t[i-1];
    }
    for(i=0;i<n-1;i++)if(m>labs(2*t[i]-t[n-1]))m=labs(2*t[i]-t[n-1]);
    printf("%ld",m);
    return 0;
}
