#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v[200005], pref[200005], suff[200005];

int main(){

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + v[i];
    for(int i = n; i >= 1; i--)
        suff[i] = suff[i+1] + v[i];

    ll res = 1e18;
    for(int i = 1; i < n; i++){
        ll x = pref[i], y = suff[i+1];
        res = min(res, abs(x-y));
    }
    cout << res << endl;
	return 0;
}
