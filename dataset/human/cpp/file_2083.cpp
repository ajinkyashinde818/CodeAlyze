#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(int argc, char *argv[]) { ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


  ll n;cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(), a.end());
  ll ans=0;
  for(int i=0;i<n;i++){
    if(i==n-1 || a[i]>=0){
      ans+=a[i];
    }else {
      ans+=abs(a[i]+a[i+1]);i++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
