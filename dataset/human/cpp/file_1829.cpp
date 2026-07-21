#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<ll> s;
ll n,m;
typedef vector<ll> v1;
v1 e;
v1 ans;

int main(){
  cin >> n >> m;
  e = v1(m);
  for(ll i = 0;i < m;i++){
    cin >> e[i];
  }
  reverse(e.begin(),e.end());
  for(ll i = 1;i <= n;i++){
    s.insert(i);
  }
  for(ll i = 0;i < m;i++){
    if(s.count(e[i])){
      s.erase(e[i]);
      ans.push_back(e[i]);
    }
  }
  for(ll i = 0;i < ans.size();i++){
    cout << ans[i] << endl;
  }
  for(ll x : s){
    cout << x << endl;
  }

}
