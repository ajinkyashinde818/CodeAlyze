#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<string> A(N),B(M);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<M;i++){
    cin >> B.at(i);
  }
  for(int i=0;i<N-M+1;i++){
    for(int j=0;j<N-M+1;j++){
      bool flag=true;
      for(int k=0;k<M;k++){
        if(A.at(i+k).substr(j,M)!=B.at(k)){
          flag=false;
          break;
        }
      }
      if(flag){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
