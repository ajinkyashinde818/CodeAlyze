#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const string YES = "Yes";
const string NO = "No";

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A;
  vector<string> B;
  A.resize(N);
  B.resize(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  bool valid = true;
  for (int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {

      for (int a = 0; a < M and valid; a++) {
        for (int b = 0; b < M and valid; b++) {
          valid = B[a][b] == A[a + i][b + j];
        }
      }
      if (valid) {
        cout << "Yes" << endl;
        return 0;
      }
      valid = true;
    }
  }
  cout << "No" << endl;
  return 0;
}
