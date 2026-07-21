#include<bits/stdc++.h>
using namespace std;

int mod = 1'000'000'007;

int fact(int n){
    long long x = 1;
    for (int i = 2; i <= n; i++){
        x *= i;
        x %= mod;
    }
    return x;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> LR(2 * n);
    long long ans = 1;
    for (int i = 0; i < 2 * n; i++){
        if (s[i] == 'W') LR[i] = (2 * n - 1 - i) % 2;
        else LR[i] = (2 * n - i) % 2;
    }
    int L = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (!LR[i]) L++;
        else {
            ans *= L;
            ans %= mod;
            L--;
        }
    }
    if (L != 0) cout << 0 << endl;
    else cout << ans * fact(n) % mod << endl;
}
