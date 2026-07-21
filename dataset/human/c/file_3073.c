#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a, b) ((a > b) ?  (b):(a))
#define rep(a, b) for(int a=0; a<b; ++a)
#define rep1(a, b) for(int a=1; a<b; ++a)


int main () {
    int k, n;
    scanf("%d%d", &k, &n);
    int house[n];
    rep(i, n)
        scanf("%d", &house[i]);
    int mini = k;
    rep1(i, n) {
        mini = min(mini, k-house[i]+house[i-1]);
    }
    mini = min(mini, house[n-1]-house[0]);
    printf("%d\n", mini);
    return 0;
}
