#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int mod = 1e9 + 7;


int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int started = 0;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = 1ll*ans*i%mod;
    }
    for(int i = 0; i < s.size(); i++) {
        int col = 0;
        if(s[i] == 'B') col = 1;
        col ^= (started&1);
        if(col == 0) {
            if(started == 0) {
                cout << 0 << endl;
                return 0;
            }
            ans = 1ll*ans*started%mod;
            started--;
        }
        else {
            started++;
        }
    }

    if(started) ans = 0;

    cout << ans << endl;

    return 0;
}
