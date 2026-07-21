#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f[26] = {0};
    for (char c: s) f[c - 'a']++;
    long long ans = 1;
    for (int i = 0; i < 26; i++)
        ans *= (1 + f[i]), ans %= mod;
    ans += mod - 1;
    ans %= mod;
    cout << ans << "\n";
    return 0;
}
