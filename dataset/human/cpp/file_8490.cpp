#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, M;
  cin >> N >> M;
  string A[N],B[M];

  // 入力の受付
  for(int i = 0; i < N; i++){
    cin >> A[i];
  } 
  for(int i = 0; i < M; i++){
    cin >> B[i];
  }

  // bool型の宣言
  bool ans = false;

  // 一行ずつ取り出して、一致しているか判断
  for(int i = 0; i <= N - M; i++){
    for(int j = 0; j <= N - M; j++){
      int cnt = 0;
      for(int k = 0; k < M; k++){
        if(B[k] == A[i + k].substr(j,M)){
          cnt++;
        }
      }
      if(cnt == M) {
        ans = true;
        break;
      }
    }
    if(ans){
      break;
    }
  }

  // 出力
  if(ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
