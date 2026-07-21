#include <bits/stdc++.h>
using namespace std;typedef long long ll;typedef vector<ll> vll;
ll mod = 1e9+7, INF = 1e18;
int main(){
  ll n, sum = 0;
  cin >> n;
  vll a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    a[i] = sum;
  }
  for (ll i = 0; i < n - 1; i++) {
    ll d = abs(a[n-1] - 2*a[i]);
    if (INF > d) INF = d;
  }
  
  cout << INF << endl;
}
