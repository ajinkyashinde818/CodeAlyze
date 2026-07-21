#include<iostream>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  bool A[N][N], B[M][M];
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    for (int j = 0; j < N; j++) A[i][j] = (s[j] == '.');
  }
  for (int i = 0; i < M; i++) {
    string s; cin >> s;
    for (int j = 0; j < M; j++) B[i][j] = (s[j] == '.');
  }
  bool matches = false;
  for (int i = 0; i < N-M+1; i++) {
    for (int j = 0; j < N-M+1; j++) {
      bool matches_in = true;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          matches_in = matches_in && (A[i+k][j+l] == B[k][l]);
        }
      }
      matches = matches || matches_in;
    }
  }
  cout << (matches ? "Yes" : "No") << endl;
}
