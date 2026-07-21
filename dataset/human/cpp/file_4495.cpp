#include<bits/stdc++.h>
using namespace std;

int main(){
  double T;
  int D,ta,tb,da,db;
  cin >> T >> D >> ta >> tb >> da >> db;

  double res = 1e9;
  for(int a=0;a*da<=D;a++){
    int va = a*da;
    for(int b=0;va+b*db<=D;b++){
      int vb = b*db;
      if(va+vb==0)continue;
      double Tp = (double)(ta*va + tb*vb)/(va+vb);
      res = min(res, abs(Tp-T));
    }
  }
  cout << fixed << setprecision(9) << res << endl;
}
