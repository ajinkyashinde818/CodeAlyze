#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<ll, ll>;
using P3 = pair<int, P>;
using PP = pair<P, P>;
constexpr int INF = 1 << 30;
constexpr ll MOD = ll(1e9) + 7;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};


int main() {
    ll n;
    string s;
    cin >> n >> s;
    ll ans = 1, cnt = 0;
    if(s.front()!='B' || s.back()!='B') ans = 0;
    for(int i=0;i<n*2;i++){
        if((cnt+s[i])%2 == 0) cnt++;
        else{
            ans *= cnt;
            cnt--;
            ans %= MOD;
        }
    }
    if(cnt != 0) ans = 0;
    for(int i=1;i<=n;i++){
        ans *= i;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
