#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), s(n+1, 0);
    for(int i = 0; i< n; i++){
        cin >> a[i];
        s[i+1] = s[i]+a[i];
    }
    ll ans = 100100100100;
    for(int i = 1; i< n; i++){
        ans = min(ans, abs(s[n]-(2*s[i])));
    }
    cout << ans << endl;
    return 0;
}
