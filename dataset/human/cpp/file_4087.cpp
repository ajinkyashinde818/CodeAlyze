#include <cstdio>
#include <cmath>
#include <queue>
#include <limits>
using namespace std;

typedef pair<double, int> P;

int x[1002], y[1002], r[1002];
double cost[1002][1002];
bool fixed[1002];
double d[1002];

int main()
{
    scanf("%d%d%d%d", &x[0], &y[0], &x[1], &y[1]);
    r[0] = r[1] = 0;

    int N;
    scanf("%d", &N);
    N += 2;
    for (int i = 2; i < N; i++)
        scanf("%d%d%d", &x[i], &y[i], &r[i]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cost[i][j] = max(hypot(x[i] - x[j], y[i] - y[j]) - r[i] - r[j], 0.);

    fill(fixed, fixed + N, false);
    fill(d, d + N, numeric_limits<double>::infinity());
    d[0] = 0;
    while (true) {
        int v = -1;
        for (int i = 0; i < N; i++) {
            if (!fixed[i] && (v == -1 || d[i] < d[v]))
                v = i;
        }
        if (v == -1)
            break;
        fixed[v] = true;
        for (int i = 0; i < N; i++) {
            d[i] = min(d[i], d[v] + cost[v][i]);
        }
    }

    printf("%.12f\n", d[1]);
}
