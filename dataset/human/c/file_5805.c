#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    long long max,min,a;
    int i,j,k;
    int tmp;
    int n;
    int m;
 
    scanf("%d",&n);
 
    scanf("%llu",&a);
    min = a;
 
    scanf("%llu",&a);
    max = a - min;
    if (min > a)
        min = a;
 
    for (i = 2; i < n; i++) {
        scanf("%lld",&a);
        if ( a-min > max)
            max = a-min;
        if (a < min)
            min = a;
    }
 
    printf("%lld\n",max);
    return 0;
}
