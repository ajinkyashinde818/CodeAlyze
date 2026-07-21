#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> A(N + 1);
   vector<int> B(N + 1);
   for (int i = 0; i < N; ++i) cin >> A[i], A[N] ^= A[i];
   for (int i = 0; i < N; ++i) cin >> B[i], B[N] ^= B[i];
   {
      vector<int> sortedA(A.begin(), A.end());
      vector<int> sortedB(B.begin(), B.end());
      sort(sortedA.begin(), sortedA.end());
      sort(sortedB.begin(), sortedB.end());
      if (sortedA != sortedB) {
         cout << "-1\n";
         return 0;
      }
   }
   N++;
   vector<int> as(A.begin(), A.end());
   sort(as.begin(), as.end());
   as.resize(unique(as.begin(), as.end()) - as.begin());
   int M = as.size();
   vector<int> root(M);
   iota(root.begin(), root.end(), 0);
   function<int(int)> getRoot = [&](int v) {
      if (v != root[v]) {
         root[v] = getRoot(root[v]);
      }
      return root[v];
   };
   auto merge = [&](int v, int u) {
      v = getRoot(v);
      u = getRoot(u);
      root[u] = v;
   };
   int ans = -2;
   for (int i = 0; i < N; ++i) {
      A[i] = lower_bound(as.begin(), as.end(), A[i]) - as.begin();
      B[i] = lower_bound(as.begin(), as.end(), B[i]) - as.begin();
      if (A[i] != B[i] || i == N - 1) {
         merge(A[i], B[i]);
         ans++;
      }
   }
   vector<bool> flag(M);
   for (int i = 0; i < N; ++i) {
      if (A[i] != B[i] || i == N - 1) {
         flag[getRoot(A[i])] = true;
      }
   }
   for (int i = 0; i < M; ++i) ans += flag[i];
   cout << ans << "\n";
}
