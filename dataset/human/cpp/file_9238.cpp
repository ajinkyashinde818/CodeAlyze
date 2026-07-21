#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> img(N);
  vector<string> tmp(M);
  for (int i = 0; i < N; ++i) cin >> img[i];
  for (int i = 0; i < M; ++i) cin >> tmp[i];
  string res = "No";
  for (int i = 0; i < N - M + 1; ++i) {
    for (int j = 0; j < N - M + 1; ++j) {
      int diff = 0;
      for (int y = 0; y < M; ++y) {
        for (int x = 0; x < M; ++x) {
          if (img[i + y][j + x] != tmp[y][x]) diff++;
        }
      }
      if (diff == 0) res = "Yes";
    }
  }
  cout << res << endl;
}
