#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    string str; cin >> str;
    ll cnt[26];
    for(int i=0;i<26;i++) cnt[i] = 0;
    for(int i=0;i<n;i++){
        cnt[str[i] - 'a']++;
    }
    ll ans = 1;
    for(int i=0;i<26;i++){
        ans = (ans * (cnt[i] + 1)) % MOD;
    }
    cout << ans - 1 << endl;
}
