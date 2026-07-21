#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define SORT(c) sort((c).begin(),(c).end())
#define ALL(a) (a).begin(),(a).end()

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

	int n;
  cin >> n;
  vector<ll> a(n+1);

  a[0] = 0;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
    a[i] += a[i-1];
  }

  ll ans = LLONG_MAX;
  for(int i=1;i<n;i++) {
    ll diff = abs((a[n] - a[i]) - a[i]);
    if(ans > diff) {
      ans = diff;
    }
  }

  cout << ans << endl;
  return 0;
}
