#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    string S;
    constexpr ll MOD = 1e9 + 7;
    cin >> N >> S;
    vector<ll> num(26, 1);
    for (char c : S) {
        num[c - 'a']++;
    }
    ll ans = 1;
    for (ll i = 0; i < 26; i++) {
        (ans *= num[i]) %= MOD;
    }

    cout << (ans + MOD - 1) % MOD << endl;
}
