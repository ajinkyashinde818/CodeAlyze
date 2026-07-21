#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<lint> num(26);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        num[c]++;
    }
    lint ans = 1;
    for (int i = 0; i < 26; i++) {
        ans = ans * (num[i] + 1) % MOD;
    }
    ans -= 1;
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
    return 0;
}
