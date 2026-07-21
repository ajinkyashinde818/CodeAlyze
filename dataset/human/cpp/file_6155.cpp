#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int N;
    int64_t C;
    cin >> N >> C;
    vector<int64_t> x(N+2), v(N+2);
    for(int i=1; i<=N; i++) {
        cin >> x[i] >> v[i];
    }

    x.back() = C;
    vector<int64_t> y(x.rbegin(), x.rend()), w(v.rbegin(), v.rend());
    partial_sum(v.begin(), v.end(), v.begin());
    partial_sum(w.begin(), w.end(), w.begin());

    for(int i=0; i<N+2; i++) {
        y[i] = C - y[i];
    }
    vector<int64_t> xm(N+2), ym(N+2);
    for(int i=1; i<=N; i++) {
        xm[i] = max(xm[i-1], v[i]-x[i]);
    }
    for(int i=1; i<=N; i++) {
        ym[i] = max(ym[i-1], w[i]-y[i]);
    }

    int64_t ans = -1;
    for(int i=0; i<=N; i++) {
        ans = max(ans, v[i] - 2*x[i] + ym[N-i]);
    }
    for(int i=0; i<=N; i++) {
        ans = max(ans, w[i] - 2*y[i] + xm[N-i]);
    }

    cout << ans << endl;
    return 0;
}
