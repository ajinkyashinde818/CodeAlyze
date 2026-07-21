#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 1000000000000000

long long abs_diff(long long a, long long b){
    return MAX(a-b, b-a);
}

void solve(void){
    int n;
    scanf("%d\n", &n);
    long long sums[n], sum;
    rep(n, i) {
        long long a;
        scanf("%lld", &a);
        sums[i] = a;
    }
    rep(n-1, i) sums[i+1] += sums[i];
    sum = sums[n-1];

    if (n == 2) printf("%lld\n", abs_diff(sums[0], sums[1]-sums[0]));
    else {
        long long min = INF;
        rep(n-1, i) if (min > abs_diff(sums[i], sum-sums[i])) min = abs_diff(sums[i], sum-sums[i]);
        printf("%lld\n", min);
    }
}

int main(void){
  solve();
  return 0;
}
