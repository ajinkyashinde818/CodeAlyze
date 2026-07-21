#include <vector>
#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

typedef complex<double> Point;

const double EPS = 1e-8;

//ãã¯ãã«a, bã®åç©
double dot(Point a, Point b)
{
    return (a.real() * b.real() + a.imag() * b.imag());
}

//ãã¯ãã«a, bã®å¤ç©
double cross(Point a, Point b)
{
    return (a.real() * b.imag() - a.imag() * b.real());
}

//ç¹a, bãç«¯ç¹ã¨ããç·åã¨ç¹cã¨ã®è·é¢
double dist_ls_p(Point a, Point b, Point c)
{
    if (dot(b - a, c - a) < EPS) return abs(c - a);
    if (dot(a - b, c - b) < EPS) return abs(c - b);
    return abs(cross(b - a, c - a)) / abs(b - a);
}

double wx[100], wy[100], wr[100];

int main()
{
    int m, n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> wx[i] >> wy[i] >> wr[i];
        }
        
        cin >> m;
        for (int i = 0; i < m; i++) {
            double x, y, tx, ty, sx, sy, r, d1, d2, d3;
            bool safe = false;
            cin >> tx >> ty >> sx >> sy;
            for (int j = 0; j < n; j++) {
                x = wx[j]; y = wy[j]; r = wr[j];
                d1 = hypot(x - sx, y - sy);
                d2 = hypot(x - tx, y - ty);
                d3 = dist_ls_p(Point(sx, sy), Point(tx, ty), Point(x, y));
                
                if ((d1 - EPS < r && r - EPS < d2) || (d2 - EPS < r && r - EPS < d1)) {
                    safe = true;
                }
                
                if (d3 - EPS < r && (d1 > r - EPS && d2 > r - EPS)) {
                    safe = true;
                }
                
            }
            
            if (safe) {
                cout << "Safe" << endl;
            } else {
                cout << "Danger" << endl;
            }
        }
    }
}
