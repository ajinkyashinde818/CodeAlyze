#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
  int N;
  cin >> N;
  ll sum = 0;
  ll mnum = 1e9;
  ll q_minus = 0;
  for(int i=0; i<N; i++) {
    ll a;
    cin >> a;
    if(a < 0) q_minus++;
    a = abs(a);
    sum += a;
    mnum = min(mnum, a);
  }
  ll ans = sum;
//  cout << mnum << endl;
  if(q_minus%2 == 1) ans -= 2*mnum;
  
  cout << ans << endl;
  return 0;
}
