#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(N);
  for (int i=0;i<N;i++){
    cin >> A[i];
  }
  for (int j=0;j<M;j++){
    cin >> B[j];
  }
  bool x=false;
  for (int a=0;a<N-M+1;a++){
    for (int b=0;b<N-M+1;b++){
      if (B[0][0]==A[a][b]){
        bool ans=true;
        for (int i=0;i<M;i++){
          for (int j=0;j<M;j++){
            if (B[i][j]!=A[a+i][b+j]){
              ans=false;
              break;
            }
          }
          if (!ans){
            break;
          }
        }
        if (ans){
          x=true;
        }
      }
    }
  }
  if (x){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
