#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N,M;
  cin >> N >> M;
  vector<string> A(N),B(M);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<M;i++){
    cin >> B[i];
  }
  for(int i=0;i<=N-M;i++){
    for(int j=0;j<=N-M;j++){
      bool flag=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(A[i+k][j+l]!=B[k][l]){
            flag=false;
          }
        }
      }
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
