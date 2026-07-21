#include <bits/stdc++.h>
using namespace std;


int main(){
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for(auto& a : A){
    cin >> a;
  }
  for(auto& b : B){
    cin >> b;
  }
  for(int row=0; row<=N-M; row++){
    for(int col=0; col<=N-M; col++){
      bool flg = true;
      for(int ii=0; ii<M; ii++){
        if(A[row+ii].substr(col, M) == B[ii]) continue;
        flg = false;
        break;
      }
      if(flg){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
