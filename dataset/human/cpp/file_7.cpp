#include <bits/stdc++.h>
using namespace std;

bool s[3002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int R, G, B, N;
  cin >> R >> G >> B >> N;
  for (int i = 0; i * B <= N; ++i) {
    s[i * B] = true;
  }

  int res = 0;
  for (int i = 0; i * R <= N; ++i) {
    for (int j = 0; i * R + j * G <= N; ++j) {
      res += s[N - i * R - j * G];
    }
  }

  cout << res << '\n';
}
