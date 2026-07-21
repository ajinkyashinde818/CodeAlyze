#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const int INF = (1<<21);
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};


int main() {
  int N; cin >> N;
  vector<long long> A(N);
  int minus = 0;
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    if (a < 0) minus++;
    A[i] = abs(a);
    ans+= A[i];
  }
  sort(A.begin(), A.end());
  if (minus % 2 == 1) {
    ans -= 2 * A[0];
  }
  cout << ans << endl;
}
