#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  ll ans=0, s=0, m = 1000000009;
  int cnt=0;
  vector<ll> a(n);
  bool z = false;
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i]==0){
      ans += s;
      m = 1000000009;
      s = 0;
      cnt = 0;
      z = true;
      continue; 
    }
    if(a[i]<0) cnt++;
    s += abs(a[i]);
    m = min(m, abs(a[i]));
    if(i==n-1){
      if(z) ans += s;
      else if(cnt%2) ans += s - 2*m;
      else ans += s;
    }
  }
  cout << ans << endl;
  return 0;
}
