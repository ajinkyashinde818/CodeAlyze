#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; ++i) cin >> A.at(i);
  for (int i = 0; i < M; ++i) cin >> B.at(i);
  bool ans = false;
  for (int i = 0; i < N - M + 1; ++i) {
    for (int j = 0; j < N - M + 1; ++j) {
      bool match = true;
      for (int k = 0; k < M; ++k) {
        for (int l = 0; l < M; ++l) {
          if (A.at(i + k).at(j + l) != B.at(k).at(l)) {
            match = false;
          }
        }
      }
      ans |= match;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
}
