#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long a[n];
  long b[n];
  vector<pair<long,long>> p(n);
  int i;
  long ans = 0;
  for(i=0;i<n;i++){
    cin >> a[i];
    b[i] = abs(a[i]);
    p[i] = make_pair(b[i],a[i]);
  }
  int cnt = 0;
  sort(p.begin(),p.end());
  
  for(i=0;i<n;i++){
    if(p[i].second<0)cnt++;
  }
  if(cnt%2==1)p[0].first*=-1;
  
  
  for(i=0;i<n;i++){
    ans += p[i].first;
  }
  cout << ans;
  
}
