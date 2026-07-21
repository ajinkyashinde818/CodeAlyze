#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == 'W') {
        cout << "0\n";
        return 0;
    }
    int cnt = 1;
    int ans = 1;
    for (int i = 1; i < 2 * n; ++i) {
        int t = (s[i] == 'W' ? 1 : 0);
        if ((cnt ^ t) % 2 == 1) {
            if (cnt == 0) {
                cout << "0\n";
                return 0;
            }
            ans = mul(ans, cnt);
            --cnt;
        } else {
            ++cnt;
        }
    }
    if (cnt != 0) {
        cout << "0\n";
        return 0;
    }
    for (int i = 2; i <= n; ++i) ans = mul(ans, i);
    cout << ans << '\n';
}
