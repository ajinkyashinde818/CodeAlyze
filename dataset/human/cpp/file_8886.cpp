#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  for(int i=0; i<M; i++){
    cin >> B.at(i);
  }
  string Ans="No";
  for(int i=0; i<N-M+1; i++){
    for(int j=0; j<N-M+1; j++){
      int k=1;
      for(int l=0; l<M; l++){
        for(int m=0; m<M; m++){
          if(B.at(l).at(m)!=A.at(i+l).at(j+m)){
            k=0;
            goto line;
          }
        }
      }
line:   if(k==1){
        Ans="Yes";
        goto lines;
      }
    }
  }
lines: cout << Ans << endl;
}
