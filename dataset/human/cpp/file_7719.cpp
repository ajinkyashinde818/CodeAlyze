#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int n,i;
  cin >> n;
  vector<int> a(n);
  for(i=0;i<n;++i){
    cin >> a[i];
  }
  vector<ll> s(n+1);
  for(i=0;i<n;++i){
    s[i+1]=s[i]+a[i];
  }
  ll x,y;
  ll mi=1000000000000+7;
  int right,left;
  right=n;
  left=0;
  for(i=1;i<n;++i){
    left=i;
    x=s[left];
    y=s[right]-s[left];
    mi=min(mi,abs(x-y));
  }
  cout << mi << endl;
  return 0;
}
