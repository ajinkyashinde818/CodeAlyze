#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mx = 1000006;
ll sam[mx], pic[mx];

int main() {
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sam[0] = a[0];

    for (ll i = 0; i < n; i++) {
        sam[i] = sam[i - 1] + a[i];
    }

   pic[n-1] = a[n - 1];

   for (ll i = n - 2; i >= 0; i--) {
    pic[i] = pic[i+1] + a[i];
   }

    ll ans = INT_MAX;

    for (ll i = 0; i < n - 1; i++) {
        ans = min(ans, abs(sam[i] - pic[i+1]));
    }

    cout << ans << endl;
}
