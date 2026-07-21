/*
 Aizu Vol-1 0129 Hide-and-Seek Supporting System.c
 2017.8.14 bal4u@uu
 ????????¨?????¨???????????????
 */

#include <stdio.h>

#define SIZE 100
int x[SIZE+5], y[SIZE+5], r[SIZE+5];
int xt, yt, xs, ys;

int between(int x1, int y1, int x2, int y2, int x, int y)
{
    int sa, sb;
    sa = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
    sb = (x1 - x2) * (x - x2) + (y1 - y2) * (y - y2);
    return (sa >= 0 && sb >= 0) || (sa < 0 && sb < 0);
}

int disCmp(int x1, int y1, int x2, int y2, int x, int y, int r2)
{
    int a, b, c, t;			/* ax + by + c = 0 */
    int squ;
    a = y1 - y2, b = x2 - x1, c = y2*x1-x2*y1;
    squ = a*a + b*b;
    if (squ == 0) return 0;
    t = (a * x) + (b * y) + c;
    t = t*t - r2*squ;
    if (t > 0) return 1;
    if (t < 0) return -1;
    return 0;
}

int main()
{
    int n, m;
    int i, dt, ds, rr;
    
    while (1) {
        scanf("%d", &n); if (!n) break;
        for (i = 0; i < n; i++) scanf("%d%d%d", x+i, y+i, &rr), r[i] = rr*rr;
        scanf("%d", &m);
        while (m-- > 0) {
            scanf("%d%d%d%d", &xt, &yt, &xs, &ys);
            for (i = 0; i < n; i++) {
                dt = (xt - x[i])*(xt - x[i]) + (yt - y[i])*(yt - y[i]);
                ds = (xs - x[i])*(xs - x[i]) + (ys - y[i])*(ys - y[i]);
                if ((dt < r[i] && ds > r[i]) || (dt > r[i] && ds < r[i])) { puts("Safe"); goto NEXT; }
                if (dt > r[i] && ds > r[i] && between(xt, yt, xs, ys, x[i], y[i]) &&
                    disCmp(xt, yt, xs, ys, x[i], y[i], r[i]) <= 0) { puts("Safe"); goto NEXT; }
            }
            puts("Danger");
        NEXT:;
        }
    }
    return 0;
}
