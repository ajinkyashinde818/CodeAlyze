#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  vector<string>A(N);for(int i=0;i<N;i++)cin>>A[i];
  vector<string>B(M);for(int i=0;i<M;i++)cin>>B[i];
  bool ans=false;
  for(int i=0;i<N-M+1;i++)for(int j=0;j<N-M+1;j++){
    bool tmp=true;
    for(int k=0;k<M;k++){
      if(A[i+k].substr(j,M)!=B[k])tmp=false;
    }
    if(tmp)ans=tmp;
  }
  cout<<(ans?"Yes":"No");
}
