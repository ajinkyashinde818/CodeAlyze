#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < M; i++) cin >> B.at(i);
  for (int j = 0; j < N-M+1; j++) {
    for (int i = 0; i < N-M+1; i++) {
      bool match = true;
      for (int y = 0; y < M; y++) {
        for (int x = 0; x < M; x++) {
          if (A.at(j+y).at(i+x) != B.at(y).at(x)) match = false;
        }
      }
      if (match) { cout << "Yes" << endl; return 0; }
    }
  }
  cout << "No" << endl;
}
