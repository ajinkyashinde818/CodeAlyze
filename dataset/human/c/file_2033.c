#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef long long ll;
int main()
{
    ll a, b, c, n=0;
    ll i;
    scanf("%lld %lld %lld",&a,&b,&c);
    for(i=0; c>0 && b>0; i++) {
        b--;
        c--;
        n += 2;
    }
    for(i=0; a>0 && c>0; i++) {
        c--;
        a--;
        n += 1;
    }
    if(c>0) {
        c--;
        n++;
    }
    n += b;
    printf("%lld",n);
    return 0;
}
