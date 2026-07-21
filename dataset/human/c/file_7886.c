#include<stdio.h>
long long a[100000];

long long gcd(long long a, long long b) {
    if(a < b)return gcd(b, a);
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

int main(){
    int n, m, i;
    scanf("%d %d", &n, &m);
    
    long long p = 1;
    for(i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        a[i] /= 2;
        long long d = gcd(a[i], p);
        p = (a[i] / d) * p;
        if (p > m) {
            puts("0");
            return 0;
        }
    }

    for(i = 0; i < n; i++) {
        if ((p / a[i]) % 2 == 0) {
            puts("0");
            return 0;
        }
    }

    printf("%lld\n", (1 + m / p) / 2);
    return 0;
}
