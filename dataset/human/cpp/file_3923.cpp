#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const double INF = 3 * (1e9) ;
bool taken[MAXN];
double d[MAXN];

struct point{
    long long x, y, r;
} p[MAXN];

double dist(point a, point b)
{
    return max(0.0, sqrt(double((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))) - double(a.r + b.r));
}

int main()
{
    cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
    p[0].r = p[1].r = 0;
   // cout << p[0].r << p[1].r << endl;
    int N;
    cin >> N;
    for (int i = 2; i < N+2; i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].r;
    }

    d[0] = 0;
    for (int i = 1; i < N+2; i++)
        d[i] = INF;

  //  cout << setprecision(10) << INF;

    int v = 0;
    while(v != 1)
    {
        taken[v] = true;
        int minidx = 1;
        for (int i = 1; i < N+2; i++)
        {
            if (!taken[i])
            {
                d[i] = min(d[i], d[v] + dist(p[i], p[v]));
                if (d[i] < d[minidx])
                    minidx = i;
            }
        }
        v = minidx;
       // cout << v << " " << d[v] << endl;
    }
    cout << setprecision(12) << d[1];
}
