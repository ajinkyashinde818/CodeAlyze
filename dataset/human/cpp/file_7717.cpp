#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,char>;
using ll=long long;

int main () {
  ll N;
  cin >> N;
  vector<ll> V(N+1,0);
  ll a;
  for (ll i=0; i<N; i++) {
    cin >> a;
    V[i+1]=V[i]+a;
  }
  ll m=pow(10, 18);
  ll S=V[N];
  for (ll i=1; i<N; i++) {
    ll T=S-2*V[i];
    //cout << T << endl;
    if (T<0) {T=-T;}
    if (m>T) {m=T;}
  }
  cout << m << endl;
}
