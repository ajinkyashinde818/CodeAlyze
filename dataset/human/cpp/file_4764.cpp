#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, r; cin >> n >> r;

    if (n>=10) cout << r << "\n";
    else cout << r + 100 * (10 - n) << "\n";

    return 0;
}
