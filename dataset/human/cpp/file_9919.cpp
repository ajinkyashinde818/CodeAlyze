#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    map<char,ll> mp;
    for (int i=0;i<n;i++) {
        mp[s[i]]++;
    }

    ll ans = 1;
    for (int i=0;i<26;i++) {
        ans *= (mp['a'+i]+1);
        ans %= mod;
    }
    ans --;
    cout << ans << endl;
}
