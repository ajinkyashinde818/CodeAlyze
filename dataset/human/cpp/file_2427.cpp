#include <bits/stdc++.h>
using ll =long long;
int main(){
  ll A=0;
  int N;
  std::cin>>N;
  std::vector<ll> add(N);
  for(int i=0;i<N;i++){
    ll B;std::cin>>B;
    A+=B;
    add[i]=(-B)-B;
  }
  std::sort(add.begin(),add.end(),std::greater<ll>());
  ll ans =A;
  for(int i=0;i<N-1;i+=2){
    ll p =add[i]+add[i+1];
    if(p>0){ans+=p;}
  }
  std::cout<<ans<<std::endl;
  return 0;
}
