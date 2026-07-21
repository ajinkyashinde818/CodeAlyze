#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2e5+7;
LL x[MAXN];
LL v[MAXN];
LL suffix[MAXN];
LL N, C;

LL solve() {
    x[N+1] = C;
    suffix[N+1] = 0;
    for (int i = N; i > 0; i--) {
        suffix[i] = suffix[i+1]+v[i]-2*(x[i+1]-x[i]);
    }
    for (int i = N; i > 0; i--) suffix[i] = max(suffix[i], suffix[i+1]);

    x[0] = 0;
    LL ans = 0;
    LL sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += v[i]-(x[i]-x[i-1]);
//        cout << i << " -> " << sum << " " << suffix[i+1] << endl;
        ans = max(ans, sum+suffix[i+1]);
    }

    return ans;
}

int main() {
    cin >> N >> C;

    for (int i = 1; i <= N; i++) cin >> x[i] >> v[i];

    LL ans = solve();
    for (int i = 1, j = N; i <= j; i++, j--) {
        if (i==j) {
            x[i] = C-x[i];
        } else {
            swap(v[i], v[j]);
            swap(x[i], x[j]);
            x[i] = C-x[i];
            x[j] = C-x[j];
        }
    }

//    for (int i = 1; i <= N; i++) cout << x[i] << " " << v[i] << endl;

    ans = max(ans, solve());

    cout << ans << endl;


    return 0;
}
