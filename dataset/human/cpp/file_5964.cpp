#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long C;
    cin >> N >> C;
    vector<long long> x(N), v(N);
    for(int i=0; i<N; ++i) cin >> x[i] >> v[i];

    vector<long long> vd(N+1, 0), v2d(N+1, 0);
    long long sum = 0;
    for(int i=0; i<N; ++i) {
        sum += v[i];
        vd[i+1] = max(vd[i], sum - x[i]);
        v2d[i+1] = max(v2d[i], sum - 2LL * x[i]);
    }

    long long res = vd[N];
    sum = 0;
    for(int i=N-1; i>=0; --i) {
        sum += v[i];
        res = max({res, sum - 2LL * (C - x[i]) + vd[i], sum - (C - x[i]) + v2d[i]});
    }
    cout << res << endl;
}
