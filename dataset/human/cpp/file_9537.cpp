#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  bool ans = false;
  bool bad = false;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      bad = false;
      if(A[i][j] == B[0][0]){
        for(int t = 0; t < M && i + t < N; t++){
          for(int k = 0; k < M && k + j < N; k++){
            if(A[i+t][j+k] != B[t][k]){
              bad = true;
              break;
            }
            if(t == M-1 && k == M-1){
              ans = true;
            }
          }
          if(bad){
            break;
          }
        }
      }
    }
  }
  if(ans){
    cout << "Yes" <<endl;
  } else{
    cout << "No" <<endl;
  }
}
