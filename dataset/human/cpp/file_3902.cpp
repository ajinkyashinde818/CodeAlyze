#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

double x[2000], y[2000], r[2000];
double G[2000][2000]; // v_n means target
double d[2000];
char visited[2000];

int main(void) {
    int n;
    double xs,ys,xt,yt;

    scanf("%lf%lf%lf%lf", &xs, &ys, &xt, &yt);
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) {
            double dis = sqrt( (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) );
            G[i][j] = G[j][i] = dis > (r[i] + r[j]) ? dis - (r[i] + r[j]) : 0.0;
        }
    for(int i=0; i<n; i++) {
        double dis = sqrt( (x[i] - xt) * (x[i] - xt) + (y[i] - yt) * (y[i] - yt) );
        G[i][n] = G[n][i] = dis > r[i] ? dis - r[i] : 0.0;
        double dis2 = sqrt( (x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys) );
        d[i] = dis2 > r[i] ? dis2 - r[i] : 0.0;
    }
   d[n] = sqrt( (xt - xs) * (xt - xs) + (yt - ys) * (yt -ys) );

    for(;;) {
        int u = n;
        for(int i=0; i<=n; i++) {
            if(!visited[i] && d[i] < d[u]) u=i;
        }
        visited[u] = 1;
        if(u == n) break;

        for(int i=0; i<=n; i++) {
            if(d[i] > d[u] + G[u][i])
                d[i] = d[u] + G[u][i];
        }
    }
    printf("%.32f\n", d[n]);
    return 0;
}
