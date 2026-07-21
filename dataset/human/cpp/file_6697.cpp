#include <iostream>
#include <cmath>
using namespace std;

bool in_circle(double x, double y, double xo, double yo, double r) {
  return ((x-xo)*(x-xo)+(y-yo)*(y-yo) < r*r);
}

int main() {
  int n, m;
  double x[100], y[100], r[100];
  double tx, ty, sx, sy, vx, vy, tp, sp, op, a, b, c, d;
  bool bt, bs, safe;
  while (1) {
    cin >> n;
    if (!n) break;
    for (int i=0; i<n; i++) {
      cin >> x[i] >> y[i] >> r[i];
    }
    cin >> m;
    for (int i=0; i<m; i++) {
      cin >> tx >> ty >> sx >> sy;
      safe = false;
      for (int j=0; j<n; j++) {
        bt = in_circle(tx, ty, x[j], y[j], r[j]);
        bs = in_circle(sx, sy, x[j], y[j], r[j]);
        if (bt ^ bs) {
          safe = true;
          break;
        } else if (!bt && !bs) {
          vx = tx - sx;
          vy = ty - sy;
          a = vy;
          b = -vx;
          c = tx*sy- ty*sx;
          d = fabs(a*x[j]+b*y[j]+c)/sqrt(a*a+b*b);
          if (d <= r[j]) {
            op = vx*x[j]+vy*y[j];
            tp = vx*tx + vy*ty;
            sp = vx*sx + vy*sy;
            if ((tp-op)*(sp-op)<0) {
              safe = true;
              break;
            }
          }
        }
      }
      if (safe) {
        cout << "Safe" << endl;
      } else {
        cout << "Danger" << endl;
      }
    }
  }
  return 0;
}
