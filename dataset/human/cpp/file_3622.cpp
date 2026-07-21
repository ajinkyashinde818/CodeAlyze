#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,A;
  cin>>N;
  ll cnt=0, ans=0, m=1e9;
  for(int i=0; i<N; i++){
    cin>>A;
    if(A<0){
      cnt++;
      A*=-1;
    }
    m=min(m,A);
    ans+=A;
  }
  if(cnt%2==1)
    ans-=m*2;
  cout<<ans<<endl;
}
