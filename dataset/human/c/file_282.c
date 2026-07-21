#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MOD 998244353
#define MAX(a,b) (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b) (a<b?a:b)
#define MIN3(a,b,c) MIN(a, MIN(b,c))
typedef long long lli;
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main()
{
    int n, i, count=0, a[100000];
    lli sum=0, ans=0, min=1e9;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        scanf("%d",a+i);
        if(a[i] < 0) {
            a[i] *= -1;
            count++;
        }
        min = MIN(min, a[i]);
        sum += a[i];
    }
    if(count%2 == 0) {
        ans = sum;
    } else {
        ans = (lli)sum - 2*min;
    }
    printf("%lld",ans);

    return 0;
}
