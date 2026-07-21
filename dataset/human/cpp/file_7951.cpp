#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  int n;cin>>n;
  ll x=0;
  ll y=0;
  ll res=-1;
  vector<ll> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
    y += v[i];
  }
  for(int i=0;i<n-1;i++){
    x += v[i];
    y -= v[i];
    if(res==-1){
      res = abs(x-y);
    }else {
      res = min(res, abs(x-y));
    }
  }
  cout<<res<<endl;

  return 0;
}
