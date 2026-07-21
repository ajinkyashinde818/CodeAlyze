#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    vector<char> s;
    for (int i = 0; i < n * 2; i++) {
        char x; cin >> x;
        s.push_back(x);
    }
    vector<int> op;
    op.push_back(0);
    int op_count = 0;
    long long res = 1;
    for (int i = 1; i < n * 2; i++) {
        int ops = 0;
        if (s[i-1] != s[i]) {
            ops = op[i-1];
            op.push_back(ops);
        } else {
            ops = (op[i-1] + 1) % 2;
            op.push_back(ops);
        }
        op_count += ops;
        if (ops == 1) {
            res *= i - 2 * (op_count - 1);
            res %= mod;
        }
    }
    if (s[0] != 'B' || s[2*n-1] != 'B') {
        cout << 0 << endl;
    } else if (op_count != n) {
        cout << 0 << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            res *= i;
            res %= mod;
        }
        cout << res << endl;
    }
    return 0;
}
