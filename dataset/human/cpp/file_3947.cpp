#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;
typedef struct { int x, y, r; } bar;

bar ps[1002];

double cost(int i, int j) {
    double dx = ps[i].x - ps[j].x, dy = ps[i].y - ps[j].y;
    return max(0e0, sqrt(dx * dx + dy * dy) - ps[i].r - ps[j].r);
}

int main() {
    int x, y, r, n;
    double d[1002];
    cin >> x >> y; ps[0] = { x, y, 0 };
    cin >> x >> y; ps[1] = { x, y, 0 };
    cin >> n; for (int i = 0; i < n; i++) { cin >> x >> y >> r; ps[i+2] = { x, y, r}; }
    d[0] = 0;
    fill(d+1, d+n+2, 1e10);
    bool used[1002] = {};
    while (true) {
        int v = -1;
        for (int i = 0; i <= n+1; i++)
            if (!used[i] && (v == -1 || d[v] > d[i])) v = i;
        if (v == -1) break;
        used[v] = true;
        for (int i = 1; i <= n+1; i++)
            d[i] = min(d[i], d[v] + cost(i, v));
    }
    cout << setprecision(12) << d[1] << endl;
}
