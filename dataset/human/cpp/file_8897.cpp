/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

vector<vector<bool>> A;
vector<vector<bool>> T;

bool Matches(const int64_t r, const int64_t c) {
  const int64_t M = static_cast<int64_t>(T.size());
  for (int64_t i = 0; i < M; ++i) {
    for (int64_t j = 0; j < M; ++j) {
      if (A[r + i][c + j] != T[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;
  A = vector<vector<bool>>(N, vector<bool>(N));
  T = vector<vector<bool>>(M, vector<bool>(M));
  for (int64_t i = 0; i < N; ++i) {
    string a;
    cin >> a;
    for (int64_t j = 0; j < N; ++j) {
      A[i][j] = a.c_str()[j] == '.';
    }
  }
  for (int64_t i = 0; i < M; ++i) {
    string a;
    cin >> a;
    for (int64_t j = 0; j < M; ++j) {
      T[i][j] = a.c_str()[j] == '.';
    }
  }
  bool matches = false;
  for (int64_t i = 0; i < N - M + 1; ++i) {
    for (int64_t j = 0; j < N - M + 1; ++j) {
      if (Matches(i, j)) {
        matches = true;
        break;
      }
    }
  }
  cout << (matches ? string("Yes") : string("No")) << endl;
  return 0;
}
