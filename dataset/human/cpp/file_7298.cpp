#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;

typedef long long ll;

ll a[200010];
ll x[200010];
ll y[200010];

int main() {
  int N; cin >> N;

  for ( int i = 0; i < N; i++ ) {
    cin >> a[i];
  }
  x[0] = a[0];
  for ( int i = 1; i < N; i++ ) {
    x[i] = x[i-1] + a[i];
  }
  y[N-1] = a[N-1];
  for ( int i = N-2; i >= 0; i-- ) {
    y[i] =  a[i] + y[i+1];
  }
  /*
  for ( int i = 0; i < N; i++ ) {
    cout << x[i] << " ";
  }
  cout << endl;

  for ( int i = 0; i < N; i++ ) {
    cout << y[i] << " ";
  }
  cout << endl;  
  */

  ll ans = 1e18;
  for ( int i = 0; i < N-1; i++ ) {
    ans = min(abs(x[i]-y[i+1]),ans);
  }

  cout << ans << endl;
  return 0;
}
