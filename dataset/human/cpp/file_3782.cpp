#include<bits/stdc++.h>

using namespace std;

int N, x[1009], y[1009], r[1009], ap[1009];
double INF = 1e14, eps = 1e-9, d[1009], mat[1009][1009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d", &x[1], &y[1], &x[2], &y[2]);
scanf ("%d", &N);
for (int i=3; i<=N + 2; i++)
    scanf ("%d %d %d", &x[i], &y[i], &r[i]);
for (int i=1; i<=N + 2; i++)
    for (int j=i + 1; j<=N + 2; j++)
    {
        int dx = x[i] - x[j], dy = y[i] - y[j];
        double D;
        if (1LL * dx * dx + 1LL * dy * dy <= 1LL * (r[i] + r[j]) * (r[i] + r[j])) D = 0.0;
        else D = (double) sqrt ((double) ((long long) 1LL * dx * dx + 1LL * dy * dy)) - r[i] - r[j];
        mat[i][j] = mat[j][i] = D;
    }
for (int i=1; i<=N + 2; i++)
    d[i] = INF;
d[1] = 0.0;
while (1)
{
    double mini = INF;
    int x = -1;
    for (int i=1; i<=N + 2; i++)
        if (d[i] < mini && ap[i] == 0)
            mini = d[i], x = i;
    if (x == -1) break;
    ap[x] = 1;
    for (int i=1; i<=N + 2; i++)
        if (ap[i] == 0 && d[x] + mat[x][i] < d[i] && i != x)
            d[i] = d[x] + mat[x][i];
}
printf ("%.10f\n", d[2]);
return 0;
}
