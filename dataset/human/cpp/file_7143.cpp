#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
 int N;
 cin >> N;
 vector<ll> a(N);
 for(int i = 0;i<N;i++){
   cin >> a[i];
 }
  vector<ll> s(N+1);//x
  s[0]= 0;
  for(int i = 0;i<N;i++){
    s[i+1] = s[i] +a[i];
  }
  
  ll sum = 0;
  for(int i = 0;i<N;i++){
    sum += a[i];
  }
  
  vector<ll> D(N+1);//y
  for(int i = 0;i<N+1;i++){
    D[i] = sum-s[i];
  }
    ll ans = 10000000000000000;
  for(int i = 1;i<N;i++){
    ans = min(ans,abs(s[i]-D[i]));
  }
  
  if(a.size() >= 3){
  cout << ans << endl;
  }
  
  else if(a.size() == 2){
    cout << abs(a[0]-a[1]) << endl;
  }
  
}
