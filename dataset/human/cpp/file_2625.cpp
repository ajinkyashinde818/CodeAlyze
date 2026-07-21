#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,i,co;
  co=0;
  cin >> n;
  vector<long long> a(n);
  long long ans=0;
  long long mi=10000000001;
  for(i=0;i<n;++i){
    cin >> a[i];
    ans=ans+abs(a[i]);
    if(a[i]<0){
      co++;
    }
    if(mi>abs(a[i])){
      mi=abs(a[i]);
    }
  }
  if(co%2==1){
    ans=ans-2*mi;
  }
  cout << ans << endl;
  return 0;
}
