#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int min(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    long long int a, b, gcd = 1, sqrt;
    scanf("%lld%lld", &a,&b);
    long long int ans;
    for (long long int i = 2; i <= min(a,b); i++) {
        if (a%i==0 && b%i==0) {
            gcd = i;
        }
    }
    ans = a*b/gcd;
    printf("%lld\n", ans);
    return 0;
}
