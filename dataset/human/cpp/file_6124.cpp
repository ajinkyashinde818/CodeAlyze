#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int N, V[100005];
ll C, X[100005];
ll A[100005], B[100005];
int main() {
  scanf("%d %lld", &N, &C);
  for (int i = 1; i <= N; i++) {
    scanf("%lld %d", &X[i], &V[i]);
  }
  X[N + 1] = C;
  ll sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += -(X[i] - X[i - 1]) + V[i];
    A[i] = max(A[i - 1], sum);
  }
  sum = 0;
  for (int i = N; i >= 1; i--) {
    sum += -abs(X[i + 1] - X[i]) + V[i];
    B[i] = max(B[i + 1], sum);
  }
  ll res = max(A[N], B[1]);
  for (int i = 1; i <= N; i++) {
    ll best = A[i] - X[i] + B[i + 1];
    res = max(res, best);
  }
  for (int i = N; i >= 1; i--) {
    ll best = B[i] - (C - X[i]) + A[i - 1];
    res = max(res, best);
  }
  printf("%lld\n", max(0LL, res));
  return 0;
}
