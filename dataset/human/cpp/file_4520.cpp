#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int T, D; cin >> T >> D;
  int ta, tb; cin >> ta >> tb;
  int da, db; cin >> da >> db;

  double mi = 1e100;
  for(int i=0; i<=D; i += da) {
    for(int j=0; i+j<=D; j += db) {
      if(i + j == 0) continue;
      int A = ta * i + tb * j;
      int B = i + j;
      double f = (double)A / B;
      if(mi > fabs(f - T)) {
        // fprintf(stderr, "i = %d, j = %d, f = %.12f\n", i, j, f);
      }
      mi = min(mi, fabs(f - T));
    }
  }
  printf("%.12f\n", mi);
  return 0;
}
