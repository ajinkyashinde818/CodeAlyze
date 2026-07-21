#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf = 1e18L + 5;

int store[200007];
ll csum[200007];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &store[i]);
    //sort(store+1, store+n+1);

    for (int i = 1; i <= n; i++) csum[i] = csum[i-1] + store[i];

    ll ans = inf;
    ll sum = 0;
    for (int i = n; i >= 2; i--) {
        sum += store[i];
        ans = min(ans, abs(sum - csum[i-1]));
    }

    cout << ans << "\n";
}
