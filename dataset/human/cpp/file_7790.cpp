#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
  int N;
  cin >> N;
  ll a[N];
  ll S[N+1];
  S[0] = 0;
  for(int i=0; i<N; i++) cin >> a[i];
  for(int i=0; i<N; i++) S[i+1] = S[i] + a[i];
  ll ans = 1e15;
  for(int i=1; i<N; i++) ans = min(ans, abs(S[N] - 2*S[i]));

  cout << ans << endl;
  return 0;
}
