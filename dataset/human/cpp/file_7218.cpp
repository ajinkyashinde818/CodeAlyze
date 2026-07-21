#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int store[200007];
ll csum[200007];


int main()
{
    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++) scanf("%d", &store[i]);
    //sort(store+1, store+n+1);
    for (int i = 1; i <= n; i++) csum[i] = csum[i-1] + store[i];

    ll ans = INT_MAX;

    for (int i = 2; i <= n; i++) {
        ll a = csum[i-1];
        ll b = csum[n] - csum[i-1];

        ans = min(ans, abs(a-b));
    }

    cout << ans << "\n";
}
