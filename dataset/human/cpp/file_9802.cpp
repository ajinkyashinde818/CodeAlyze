#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const ll MOD = 1e9+7;
ll n;
string s;

int main() {
    cin >> n >> s;
    vector<ll> alp(26, 1);
    for(int i = 0; i < n; ++i) {
        int check = s.at(i) - 'a';
        alp.at(check)++;
    }

    ll ans = 1;
    for(int i = 0; i < 26; ++i) {
        ans *= alp.at(i);
        ans %= MOD;
    }
    ans--;
    if(ans < 0) cout << ans+MOD << endl;
    else cout << ans << endl;
}
