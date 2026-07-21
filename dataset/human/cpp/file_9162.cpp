#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> A(N, vector<char>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<char>> B(M, vector<char>(M));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cin >> B.at(i).at(j);
    }
  }
  for (int i = 0; i + (M - 1) < N; i++) {
    for (int j = 0; j + (M - 1) < N; j++) {
      bool b = 1;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (A.at(i + k).at(j + l) != B.at(k).at(l)) b = 0;
        }
      }
      if (b) return cout << "Yes" << "\n", 0;
    }
  }
  cout << "No" << "\n";
}
