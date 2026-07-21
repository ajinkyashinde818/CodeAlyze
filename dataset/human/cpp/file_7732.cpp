#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll a[222222];

int main() {
   cin >> n;
   ll sum = 0;
   for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
   }

   ll ans = 1e16;
   ll rui = 0;
   for (int i = 0; i < n-1; i++) {
      rui += a[i];
      ll b = sum - rui;
      ans = min(ans, abs(rui - b));
   }

   cout << ans << endl;

   return 0;
}
