#include <iostream>

using namespace std;

char A[50][50] = {{0}};
char B[50][50] = {{0}};

bool IsSubset(int i, int j, int M) {
  for (int k = 0; k < M; ++k) {
    for (int l = 0; l < M; ++l) {
      if (A[i + k][j + l] != B[k][l]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j) cin >> A[i][j];
  for (int i = 0; i < M; ++i)
    for (int j = 0; j < M; ++j) cin >> B[i][j];

  for (int i = 0; i <= N - M; ++i) {
    for (int j = 0; j <= N - M; ++j) {
      if (IsSubset(i, j, M)) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
