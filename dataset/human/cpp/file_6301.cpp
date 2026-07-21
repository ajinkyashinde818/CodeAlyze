#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a[200005] = {}, c = 0;
    ll z = 1;
    bool b = 0;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n + n; i++) {
        if (s[i - 1] == 'B') {
            if (!b) a[i] = 1, b = 1;
            else b = 0;
        } else {
            if (!b) b = 1;
            else a[i] = 1, b = 0;
        }
    }
    int d = 0;
    for (int i = 1; i <= n + n; i++) if (a[i]) d++;
    if (d != n) z = 0;
    for (int i = 1; i <= n + n; i++) {
        if (a[i]) c++;
        else z = z * c % mod, c--;
    }
    for (int i = 1; i <= n; i++) z = z * i % mod;
    cout << z;
}
