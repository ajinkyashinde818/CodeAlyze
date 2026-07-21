#include <bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
    int n;
    cin >> n;
    lint c;
    cin >> c;
    vector<lint> x(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> v[i];
    }

    vector<lint> rpos(n + 1), rmax(n + 1), rmaxb(n + 1);
    // b は折り返すときの値
    lint rv_sum = 0;
    for (int i = 1; i <= n; i++) {
        rpos[i] = x[i];
        rv_sum += v[i];
        rmax[i] = max(rmax[i - 1], rv_sum - rpos[i]);
        rmaxb[i] = max(rmaxb[i - 1], rv_sum - 2 * rpos[i]);
    }
    vector<lint> lpos(n + 1), lmax(n + 1), lmaxb(n + 1);
    lint lv_sum = 0;
    for (int i = 1; i <= n; i++) {
        lpos[i] = c - x[n + 1 - i];
        lv_sum += v[n + 1 - i];
        lmax[i] = max(lmax[i - 1], lv_sum - lpos[i]);
        lmaxb[i] = max(lmaxb[i - 1], lv_sum - 2 * lpos[i]);
    }

    lint ans = 0;
    for (int i = 0; i <= n; i++) {
        // i だけ右に進む
        lint cand = max(rmax[i] + lmaxb[n - i], rmaxb[i] + lmax[n - i]);
        ans = max(ans, cand);
    }
    cout << ans << endl;
    return 0;
}
