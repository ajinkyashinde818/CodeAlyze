#include "bits/stdc++.h"
using namespace std;
typedef long long li;

li c;
li calc(vector<li> xs, vector<li> vs) {
    li n = xs.size();
    vector<li> acc(n + 1);
    for (int i = 0; i < n; ++i) {
        acc[i + 1] = acc[i] + vs[i];
    }
    vector<li> single(n + 1);
    for (int i = 0; i < n; ++i) {
        single[i + 1] = acc[i + 1] - xs[i];
    }

    li ans = 0;
    li max_double = 0;
    for (int su = n; su >= 0 ; --su) {
        li d_profit = acc[n] - acc[su] - (su == n ? 0 : (c - xs[su])) * 2;
        max_double = max(max_double, d_profit);
        li s_profit = single[su];
        li profit = s_profit + max_double;
        ans = max(ans, profit);
    }
    return ans;
}

int main() {
    li n;
    cin >> n >> c;

    vector<li> xs(n), vs(n);
    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> vs[i];
    }

    li ans = 0;
    ans = max(ans, calc(xs, vs));
    vector<li> rxs, rvs;
    for (int j = n-1; j >= 0 ; --j) {
        rxs.push_back(c - xs[j]);
        rvs.push_back(vs[j]);
    }

    ans = max(ans, calc(rxs, rvs));

    cout << ans << endl;
    return 0;
}
