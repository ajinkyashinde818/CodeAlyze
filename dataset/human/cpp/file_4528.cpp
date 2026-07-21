#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

int main() {
  int T, D;

  while (cin >> T >> D) {
    int ta, tb; cin >> ta >> tb;
    int da, db; cin >> da >> db;
    double ans = 999999999;

    for (int i = 0; i * da <= D; i++) {
      int va = i * da;
      for (int j = 0; va + j * db <= D; j++) {
        int vb = j * db;
        double t = (double)(ta * va + tb * vb) / (va + vb);
        ans = min(ans, fabs(t - T));
      }
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
}
