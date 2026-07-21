#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<string> A(55),B(55);
  for(int i=0;i<N;i++){cin >> A[i];}
  for(int i=0;i<M;i++){cin >> B[i];}
  string ans="No";
  int a=0;
  for(int i=0;i+M<=N;i++){
    for(int j=0;j+M<=N;j++){
      a=1;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(A[i+k][j+l]!=B[k][l]){a=0;}
        }
      }
      if(a==1){ans="Yes";}
    }
  }
  cout << ans << endl;
}
