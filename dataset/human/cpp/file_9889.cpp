#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e10;
const ll MOD = 1e9 + 7;

int main() {
    int N;
    string S;
    cin >> N >> S;

    unordered_map<char, ll> counter;
    for (char c : S) {
        if (counter.find(c) == counter.end()) {
            counter[c] = 1;
        } else {
            counter[c]++;
        }
    }

    ll ans = 1;
    for (auto kv : counter) {
        ans = (ans * (kv.second + 1)) % MOD;
    }
    ans--;
    cout << ans << endl;
}
