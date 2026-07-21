#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    for (ll i = 1; i * (i + 1) / 2 <= N; i++) {
        if (i * (i + 1) / 2 == N) {
            cout << "Yes" << endl;
            cout << i + 1 << endl;
            vector<vector<ll>> ans(i + 1);
            ll num = 1;
            for (ll j = 0; j < i + 1; j++) {
                for (ll k = j + 1; k < i + 1; k++) {
                    ans[j].push_back(num);
                    ans[k].push_back(num);
                    num++;
                }
                cout << ans[j].size() << " ";
                for (ll k = 0; k < i; k++) {
                    printf("%lld%c", ans[j][k], " \n"[k == i - 1]);
                }
            }
            return 0;
        }
    }

    cout << "No" << endl;
}
