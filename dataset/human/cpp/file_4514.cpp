/*
 * 2656.cc: Taps
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const double DINF = 1.0e60;

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  double t, d, ta, tb, da, db;
  cin >> t >> d >> ta >> tb >> da >> db;

  double va, vb, mindt = DINF;
  for (int ai = 0; (va = da * ai) <= d; ai++) {
    for (int bi = 0; va + (vb = db * bi) <= d; bi++) {
      double v = va + vb;
      if (v == 0.0) continue;
      double tt = (ta * va + tb * vb) / v;
      double dt = abs(t - tt);
      if (mindt > dt) mindt = dt;
    }
  }
  printf("%.10lf\n", mindt);
  return 0;
}
