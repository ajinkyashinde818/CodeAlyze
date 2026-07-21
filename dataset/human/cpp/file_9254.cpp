#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> A(N, vector<char>(N)), B(M, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cin >> B.at(i).at(j);
    }
  }
  
  bool E = false;
  for (int k = 0; k <= N - M; k++) {
    for (int l = 0; l <= N - M; l++) {
      int X = 0;
      for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
          if (A.at(i + k).at(j + l) == B.at(i).at(j)) X++;
        }
      }
      if (X == M * M) {
        E = true;
        break;
      }
    }
  }
  
  if (E) cout << "Yes" << endl;
  else cout << "No" << endl;
}
