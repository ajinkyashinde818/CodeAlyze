#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> picture_A(N), picture_B(M);
  for (int i = 0; i < N; i++) cin >> picture_A.at(i);
  for (int j = 0; j < M; j++) cin >> picture_B.at(j);
  
  bool answer = false;
  for (int i = 0; i <= N - M; i++) {
    for (int j = 0; j <= N - M; j++) {
      for (int k = 0; k < M; k++) {
        string tmp = picture_A.at(i + k).substr(j, M);
        if (tmp != picture_B.at(k)) break;
        if (k == M - 1) answer = true;
      }
      if (answer) break;
    }
    if (answer) break;
  }
  
  if (answer) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
