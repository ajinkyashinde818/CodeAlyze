#include <bits/stdc++.h>
using namespace std;

typedef long long int LLI;

int N;
LLI C;
LLI xs[114514];
LLI vs[114514];
LLI lsum[114514];
LLI rsum[114514];
LLI lmax[114514];
LLI rmax[114514];
LLI ans;

int main() {
  scanf("%d%lld", &N, &C);
  for (int i=1; i<=N; i++) {
    scanf("%lld%lld", &xs[i], &vs[i]);
    lsum[i] = lsum[i-1] + vs[i] - (xs[i]-xs[i-1]);
    lmax[i] = max(lmax[i-1], lsum[i]);
    ans = max(ans, lsum[i]);
  }

  xs[N+1] = C;
  for (int i=1; i<=N; i++) {
    rsum[i] = rsum[i-1] + vs[N+1-i] - (xs[N+2-i]-xs[N+1-i]);
    rmax[i] = max(rmax[i-1], rsum[i]);
    ans = max(ans, rsum[i]);
  }

  for (int i=1; i<=N; i++) {
    LLI t = lsum[i] - xs[i] + rmax[N-i];
    //printf("%d: lsum[i]:%lld - xs[i]:%lld + rmax[N-i]:%lld\n", i, lsum[i], xs[i], rmax[N-i]);
    ans = max(ans, t);
  }

  for (int i=1; i<=N; i++) {
    LLI t = rsum[i] - (C-xs[N+1-i]) + lmax[N-i];
    //printf("%d: rsum[i]:%lld - (C-xs[N+1-i]):%lld + lmax[N-i]:%lld\n", i, rsum[i], C-xs[N+1-i], lmax[N-i]);
    ans = max(ans, t);
  }

  printf("%lld\n", ans);
}
