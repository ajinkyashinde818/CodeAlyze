#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<string> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
   vector<string> B(M);
  for(int i = 0; i < M; i++){
    cin >> B[i];
  }
  
  for(int i = 0; i <= N-M; i++){
    for(int j = 0; j <= N-M; j++){
      int  I = i;
      while(I < i+M){
        if(A[I].substr(j, M) != B[I-i]){
              break;
         };
        I++;
        if(I == M+i){
              cout << "Yes" << endl;
              return 0;
        }
      }            
    }
  }
  
  cout << "No" << endl;
  return 0;
}
