#include<stdio.h>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  int a[N];
  long long sum[N+1];
  sum[0] = 0;
  for (int i=1 ; i<=N ; i++) {
    scanf("%d", &a[i]);
    sum[i] = sum[i-1] + a[i];
  }
  long long res = 1000000000000000000LL;
  long long x, y;
  for (int i=1 ; i<N ; i++) {
    x = sum[i];
    y = sum[N] - sum[i];
    res = min(res, abs(x-y));
  }
  printf("%lld\n", res);
}
