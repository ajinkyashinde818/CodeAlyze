#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=1;i<n;i++){
    a[i]=a[i]+a[i-1];
  }
  ll ans=100000000000;
  for(int i=0;i<n-1;i++){
    ans=min(ans,abs(a[i]-(a[n-1]-a[i])));
  }
  cout<<ans<<endl;
  return 0;
}
