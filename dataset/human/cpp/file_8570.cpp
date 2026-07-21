#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for (auto &v : A) cin >> v;
  for (auto &v : B) cin >> v;
  
  bool b = false;
  vector<string> isB;
  for (int i = 0; i < N-M+1; i++) {
    for (int j = 0; j < N-M+1; j++) {
      for (int k = 0; k < M; k++) {
        string s = A[i+k].substr(j,M);
        isB.push_back(s);
      }
      if (isB == B) b = true;
      else isB.clear();
    }
  }
  cout << (b ? "Yes" : "No") << endl;
}
