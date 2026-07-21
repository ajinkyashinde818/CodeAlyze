#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 100005;

int N, A[MAX_N], B[MAX_N], cp_val[MAX_N << 1];
int cnt[MAX_N << 1], fa[MAX_N];

int find(int x) {
  return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
  scanf("%d", &N);
  int xor_val = 0, tot = 0;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    xor_val ^= A[i], cp_val[++tot] = A[i];
  }
  A[N + 1] = xor_val; cp_val[++tot] = A[N + 1];
  
  xor_val = 0;
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &B[i]);
    xor_val ^= B[i], cp_val[++tot] = B[i];
  }
  B[N + 1] = xor_val, cp_val[++tot] = B[N + 1];

  sort(cp_val + 1, cp_val + tot + 1);
  tot = unique(cp_val + 1, cp_val + tot + 1) - cp_val - 1;

  N++;
  for (int i = 1; i <= N; ++i) {
    A[i] = lower_bound(cp_val + 1, cp_val + tot + 1, A[i]) - cp_val;
    B[i] = lower_bound(cp_val + 1, cp_val + tot + 1, B[i]) - cp_val;
    cnt[A[i]]--, cnt[B[i]]++;
  }
  
  for (int i = 1; i <= tot; ++i)
    if (cnt[i]) {
      puts("-1");
      return 0;
    }

  static bool vis[MAX_N];
  for (int i = 1; i <= N; ++i) fa[i] = i;

  int res = 0;
  for (int i = 1; i < N; ++i) 
    if (A[i] != B[i]) {
      vis[A[i]] = vis[B[i]] = 1;
      if (find(A[i]) != find(B[i])) fa[find(A[i])] = find(B[i]);
      res++;
    }
  vis[A[N]] = vis[B[N]] = 1;
  for (int i = 1; i <= tot; ++i)
    if (vis[i] && find(i) == i) res++;

  printf("%d\n", res - 1);
  return 0;
}
