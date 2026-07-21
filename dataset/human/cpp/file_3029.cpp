#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  int N;
  cin>>N;
  vector<ll> a(N);
  ll fu=0;
  ll gokei=0;
  ll saisyo=10e10;
  for(int i=0;i<N;i++){
    cin>>a[i];
    gokei+=abs(a[i]);
    saisyo=min(saisyo,abs(a[i]));
    if(a[i]<0) fu++;
  }
  
  if(fu%2==0){
    cout<<gokei<<endl;
  }else{
    cout<<gokei-2*saisyo<<endl;
  }

  return 0;
}
