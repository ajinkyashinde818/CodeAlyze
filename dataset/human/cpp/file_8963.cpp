#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; ++i) cin >> A.at(i);
  for (int i = 0; i < M; ++i) cin >> B.at(i);

  bool exist = false;
  for (int ly = 0; ly < N; ++ly) {
    for (int lx = 0; lx < N; ++lx) {
      if (ly + M - 1 >= N || lx + M - 1 >= N) {
        continue;
      }
      bool match = true;
      for (int y = 0; y < M; ++y) {
        for (int x = 0; x < M; ++x) {
          if (A.at(ly + y).at(lx + x) != B.at(y).at(x)) {
            match = false;
          }
        }
      }
      if (match) {
        exist = true;
      }
    }
  }

  if (exist) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  return 0;
}
