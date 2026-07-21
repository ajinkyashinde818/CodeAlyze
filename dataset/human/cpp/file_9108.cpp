#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, M;
  cin >> N >> M;

  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<string> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  string answer = "No";

  for (int i = 0; i <= N - M; i++) {

    vector<string> a(M);
    for (int j = 0; j <= N - M; j++) {
      for (int k = 0; k < M; k++) {
        a[k] = A[i + k].substr(j, M);
      }

      if (B == a) {
        answer = "Yes";
        break;
      }

    }

    if (answer == "Yes") {
      break;
    }

  }

  cout << answer << endl;

}
