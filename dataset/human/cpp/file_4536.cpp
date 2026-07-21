#include <bits/stdc++.h>
using namespace std;

int main(void){
  int T, D, ta, tb, da, db; cin >> T >> D >> ta >> tb >> da >> db;
  double t, A, B;
  A = 0; B = 0;
  while(1){
    if(B + db > D) break;
    B += db;
  }
  double ans = 111;
  while(B >= 0){
    A = 0;
    while(1){
      t = (ta*A + tb*B)/(A + B);
      ans = min(ans, abs((double)T-t));
      A += (double)da;
      if(A+B > D) break;
    }
    B -= (double)db;
  }
  printf("%f\n", ans);
  return 0;
}
