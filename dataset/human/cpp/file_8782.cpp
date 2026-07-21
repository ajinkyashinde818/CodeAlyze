#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;

int main(){
  int N,M;cin >> N >> M;
  vector<string> A(N);
  vector<string> B(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<M;i++){
    cin >> B[i];
  }
  for(int k=0;k<N-M+1;k++){
    for(int l=0;l<N-M+1;l++){
      bool match = true;
      for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
          if(A[i+k][j+l]!=B[i][j]){
            match = false;
            break;
          }
        }
      }
      if(match){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
