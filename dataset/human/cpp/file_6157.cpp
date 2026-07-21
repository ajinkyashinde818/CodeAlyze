#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 1e5 + 10;

int N;

llint C;
llint x[MAXN], v[MAXN];
llint prefL[MAXN], prefR[MAXN], L[MAXN], R[MAXN];

int main(void) {
  scanf("%d%lld", &N, &C);
  for (int i = 0; i < N; ++i)
    scanf("%lld%lld", &x[i + 1], &v[i + 1]);

  x[N + 1] = C;

  llint sol = 0;
  for (int i = 0; i < N; ++i) {
    R[i + 1] = R[i] + v[i + 1] - (x[i + 1] - x[i]);
    prefR[i + 1] = max(prefR[i], R[i + 1]);
    sol = max(sol, prefR[i + 1]);
  }

  for (int i = 0; i < N; ++i) {
    L[i + 1] = L[i] + v[N - i] - (x[N - i + 1] - x[N - i]);
    prefL[i + 1] = max(prefL[i], L[i + 1]);
    sol = max(sol, prefL[i + 1]);
  }

  //for (int i = 1; i <= N; ++i)
    //printf("%d ", R[i]);
  //printf("\n");

  //for (int i = 1; i <= N; ++i)
    //printf("%d ", L[i]);
  //printf("\n");


  for (int i = 1; i <= N; ++i) {
    sol = max(sol, R[i] - x[i] + prefL[N - i]);
    sol = max(sol, L[i] - (x[N + 1] - x[N - i + 1]) + prefR[N - i]);
  }

  printf("%lld\n", sol);

  return 0;
}
