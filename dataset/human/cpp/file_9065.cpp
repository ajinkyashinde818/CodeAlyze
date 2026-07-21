#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M; cin >> N >> M;
  string A[50],B[50];
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<M; i++) cin >> B[i];
  
  bool exist=false;
  for(int i=0; i<N-M+1; i++){
    for(int j=0; j<N-M+1; j++){
      bool match=true;
      for(int k=0; k<M; k++){
        if(A[i+k].substr(j,M)!=B[k]){
          match=false;
          break;
        }
      }
      if(match==true){
        exist=true;
        break;
      }
    }
    if(exist==true) break;
  }
  cout << (exist==true?"Yes":"No") << endl;
}
