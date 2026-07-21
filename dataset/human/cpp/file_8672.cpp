#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,M;
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
  int count = 0;
  int K = 0;
  int L = 0;
  for (int i = 0; i < N+1-M; i++) {
    for (int j = 0; j < N+1-M; j++) {
      for (int k = i; k < i+M; k++) {
        for (int l = j; l < j+M; l++) {
          if (A.at(k).at(l) != B.at(K).at(L)){
            count++;
          }
          if (K == M-1 && L == M-1 && count == 0){
            cout << "Yes" << endl;
            return 0;
          }
          if (L < M-1){
            L++;
          }
          else{
            K++;
            L = 0;
          }
        }
      }
      K = 0;
      L = 0;
      count = 0;
    }
  }
  cout << "No" << endl;
}
