#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

ll n;
string s;
void solve();

void input() {
    cin >> n >> s;
}

void solve() {
    if (s[0] == 'W') {
        std::cout << 0 << endl;
        return;
    }
    
    ll ans = 1;
    ll cnt = 1;
    bool left = 1;
    for (ll i = 1; i < sz(s); i++) {
        if (s[i] == s[i-1]) {
            left = !left;
        }
        if (left) {
            cnt++;
        } else {
            ans = (ans * cnt) % MOD;
            cnt--;
        }
    }
    if (cnt != 0) {
        std::cout << 0 << endl;
        return;
    }
    for (ll i = 2; i <= n; i++) ans = (ans * i) % MOD;
    std::cout << ans << endl;
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
