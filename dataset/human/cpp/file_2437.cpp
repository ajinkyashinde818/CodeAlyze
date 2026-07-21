#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int64_t> B(N);
  int cnt=0;
  for(int i=0;i<N;++i){
    int64_t A;
    cin>>A;
    
    if(A<=0)  ++cnt;
    B[i]=abs(A);
  }

  int64_t ans=0;
  if(cnt%2==0){
    for(int i=0;i<N;++i){
      ans += B[i];
    }
    cout<<ans<<endl;
  }
  else{
    sort(B.begin(),B.end());
    for(int i=0;i<N;++i){
      if(i==0) ans -= B[i];
      else ans += B[i];
    }
    cout<<ans<<endl;
  }
}
