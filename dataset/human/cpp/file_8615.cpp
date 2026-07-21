#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> A(N, vector<char> (N));
  vector<vector<char>> B(M, vector<char> (M));
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < M; j++) {
      cin >> B.at(i).at(j);
    }
  }
  bool can= true;
  bool ans = false;
  for(int i = 0; i <= N-M; i++) {
    if(ans) break;
    for(int j = 0; j <= N-M; j++) {
      if(ans) break;
      can = true;
      for(int k = 0; k < M; k++) {
        if(!can) break;
        for(int l = 0; l < M; l++) {
          if(A.at(i+k).at(j+l) != B.at(k).at(l)) {
            can = false;
            break;
          }
        }
        if(k == M-1 && can) ans = true;
      }
    }
  }
  if(ans) cout << "Yes" << endl;
  if(!ans) cout << "No" << endl;
}
