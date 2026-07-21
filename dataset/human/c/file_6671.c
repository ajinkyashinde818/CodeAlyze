#include <stdio.h>

void chmax(long *a, long b) {
    if(*a < b) *a = b;
}

void chmin(long *a, long *b) {
    if(*a > *b) *a = *b;
}


int main(void) {

    int n; scanf("%d", &n);

    long r[n];
    long ans = -9999999999, minv = 9999999999;
    for(int i = 0; i < n; i++) scanf("%ld", &r[i]);

    for(int i = 0; i < n; i++) {
        chmax(&ans, r[i]-minv);
        chmin(&minv, &r[i]);
    }

    printf("%ld\n", ans);

    return 0;
}
