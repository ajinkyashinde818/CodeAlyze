#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int64 N, C, X[100000], V[100000];

  cin >> N >> C;
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> V[i];
  }

  int64 ret = 0;

  auto solve = [&]() {

    int64 sum = 0;
    int64 pv = 0;
    vector< int64 > get(N);
    for(int i = 0; i < N; i++) {
      sum -= X[i] - pv;
      sum += V[i];
      ret = max(ret, sum);
      get[i] = sum;
      pv = X[i];
    }
    for(int i = 1; i < N; i++) {
      get[i] = max(get[i], get[i - 1]);
    }

    sum = 0;
    pv = C;
    for(int i = N - 1; i >= 0; i--) {

      sum -= pv - X[i];
      sum += V[i];
      ret = max(ret, sum);
      pv = X[i];

      int64 sum2 = sum;
      sum2 -= C - X[i];
      if(i > 0) ret = max(ret, sum2 + get[i - 1]);
    }
  };

  solve();
  for(int i = 0; i < N; i++) {
    X[i] = C - X[i];
  }
  reverse(X, X + N);
  reverse(V, V + N);
  solve();

  cout << ret << endl;
}
