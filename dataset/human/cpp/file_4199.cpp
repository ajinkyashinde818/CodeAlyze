#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

int n, x[1002], y[1002], r[1002];
double d[1002][1002], v[1002];
set<pair<double, int>> q;
set<pair<double, int>>::iterator qq[1002];

int main() {
    scanf("%i %i %i %i %i", x, y, x+1, y+1, &n);
    d[0][1] = d[1][0] = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2));
    for (int i = 2; i < n + 2; ++i) {
        scanf("%i %i %i", x + i, y + i, r + i);
        for (int j = 0; j < i; ++j) {
            d[j][i] = d[i][j] = max((double)0, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) - r[i] - r[j]);
        }
    }
    for (int i = 1; i < n + 2; ++i) v[i] = 1e11, qq[i] = q.end();
    qq[0] = q.emplace(0, 0).first;
    while (q.size()) {
        auto p = *q.begin();
        q.erase(q.begin());
        qq[p.second] = q.end();
        for (int i = 0; i < n + 2; ++i) {
            double w = p.first + d[i][p.second];
            if (w < v[i]) {
                if (qq[i] != q.end()) q.erase(qq[i]);
                qq[i] = q.emplace(v[i] = w, i).first;
            }
        }
    }
    printf("%.10f\n", v[1]);
    return 0;
}
