#include <bits/stdc++.h>
using namespace std;
void init_ios() {ios_base::sync_with_stdio(false); cin.tie(nullptr);}

long long N, C;

int main() {
    init_ios();
    
    cin >> N >> C;
    vector<pair<long long, long long>> xv(N);
    for (auto& p : xv) cin >> p.first >> p.second;

    auto res = 0LL;

    vector<long long> cw(N), ccw(N);

    // clockwise
    {
        auto pos = 0LL, col = 0LL, mx = -(1LL << 62);
        for (int i = 0; i < N; ++i) {
            col += -(xv[i].first - pos) + xv[i].second;
            pos = xv[i].first;
            mx = max(mx, col);
            cw[i] = mx;
        }
        res = max(res, mx);
    }

    // counterclockwise
    {
        auto pos = C, col = 0LL, mx = -(1LL << 62);
        for (int i = N - 1; 0 <= i; --i) {
            col += -(pos - xv[i].first) + xv[i].second;
            pos = xv[i].first;
            mx = max(mx, col);
            ccw[i] = mx;
        }
        res = max(res, mx);
    }

    // counterclockwise -> clockwise
    {
        auto pos = C, col = 0LL;
        for (int i = N - 1; 1 <= i; --i) {
            col += -(pos - xv[i].first) + xv[i].second;
            pos = xv[i].first;
            res = max(res, col - (C - pos) + cw[i - 1]);
        }
    }

    // clockwise -> counterclockwise
    {
        auto pos = 0LL, col = 0LL;
        for (int i = 0; i < N - 1; ++i) {
            col += -(xv[i].first - pos) + xv[i].second;
            pos = xv[i].first;
            res = max(res, col - pos + ccw[i + 1]);
        }
    }

    cout << res << endl;

    return 0;
}
