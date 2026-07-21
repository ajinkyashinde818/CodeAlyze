#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  string A[60], B[60];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  bool ans = false;
  for (int i = 0; i <= N - M; i++) {
    for (int j = 0; j <= N - M; j++) {
      bool check = true;
      for (int k = 0; k < M; k++) {
        if (A[i + k].substr(j, M) != B[k]) {
          check = false;
          break;
        }
      }
      if (check) ans = check;
    }
  }

  cout << (ans ? "Yes" : "No") << endl;
}
