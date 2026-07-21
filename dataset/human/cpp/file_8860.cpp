#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<M; i++) cin >> B[i];

  string ans = "No";
  // A の中には B が N-M+1 個あるのでそれを検査
  for (int y=0; y<N-M+1; y++) {
    for (int x=0; x<N-M+1; x++) {
      bool flag = true;

      for (int i=0; i<M; i++) {
        for (int j=0; j<M; j++) {
          if (A[y+i][x+j] != B[i][j]) flag = false;
        }
      }

      if (flag) {
        ans = "Yes";
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
