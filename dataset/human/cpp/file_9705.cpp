#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int MAX = 100001;

long long fac[MAX], finv[MAX], inv[MAX];

void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long mod_comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt.at(s.at(i) - 'a')++;
    }
    comb_init();
    
    long long cnt_b = 0, x = 1;
    for (int i = 0; i < 26; i++) {
        if (cnt.at(i) >= 2) {
            x *= cnt.at(i) + 1;
            x %= MOD;
        }
        else if (cnt.at(i) == 1){
            cnt_b++;
        }
    }
    
    long long sum1 = 0;
    for (int i = 0; i <= cnt_b; i++) {
        sum1 += mod_comb(cnt_b, i);
        sum1 %= MOD;
    }
    
    long long ans = sum1 % MOD * x % MOD;
    cout << ans - 1 << endl;
}
