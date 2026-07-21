#include <bits/stdc++.h>

using namespace std;

namespace {
    int T, D;
    int ta, tb;
    int da, db;
    void input() {
        cin >> T >> D;
        cin >> ta >> tb;
        cin >> da >> db;
    }

    void solve() {
        double ans = min(abs(T - ta), abs(T - tb));
        for (int i = 0; i * da <= D; i++) {
            for (int j = 0; i * da + j * db <= D; j++) {
                if (i == 0 && j == 0) continue;
                double t = double(i * da * ta + j * db * tb) / (i * da + j * db);
                ans = min(ans, abs(T - t));
            }
        }
        printf("%.12f\n", ans);
    }
}

int main() {
    input(); solve();
    return 0;
}
