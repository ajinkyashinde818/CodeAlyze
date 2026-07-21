#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

const ll mod = 1e9 + 7;
int n;
char S[200005];
int C[200005];
void input() {
    cin >> n >> S + 1;
}

void calc() {
    int cnt[2] = {};
    int sum = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int c = i & 1;
        c ^= (S[i] == 'W');
        C[i] = c;
        if (c == 1) sum++;
        else sum--;
        if (sum < 0) return;
    }
    if (sum != 0) return;
    sum = 0;
    ll ans = 1;
    for (int i = 1; i <= n; i++) ans = ans * i % mod;
    for (int i = 1; i <= 2 * n; i++) {
        if (C[i] == 1) sum++;
        else {
            ans = ans * sum % mod;
            sum--;
        }
    }
    cout << ans;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    calc();
    cout << 0;
    return 0;
}
