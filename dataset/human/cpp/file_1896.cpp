#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int Q;
    cin >> Q;
    while(Q--) {
        string s;
        cin >> s;
        int n = 0;
        for(int i=0; i<8; ++i) {
            n <<= 4;
            if(isdigit(s[i])) {
                n += s[i] - '0';
            } else {
                n += s[i] - 'a' + 10;
            }
        }
        double res = 0;
        double d = 1;
        {
            int t = n & ((1LL << 31) - 1);
            res += (t >> 7);
        }
        int cnt = 1;
        for(int i=6; i>=0; --i) {
            d /= 2;
            if(n & (1 << i)) {
                res += d;
                cnt = 6 - i + 1;
            }
        }
        cout << fixed << setprecision(cnt);
        if(n & (1 << 31)) {
            cout << -res << endl;
        } else {
            cout << res << endl;
        }
    }
}
