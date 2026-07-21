#include <iostream>
#include <cstdio>
using namespace std;

int main() {

  int t,d;
  cin >> t >> d;
  int ta,tb,da,db;
  cin >> ta >> tb;
  cin >> da >> db;

  double ans = 10000000;
  for(int i=0;i<=d/da;i++)
    for(int j=0;j<=d/db;j++) {
      int va = i*da;
      int vb = j*db;
      if(va+vb < 1 || va + vb > d) continue;
      double ond = 1.0*(ta*va+tb*vb)/(va+vb);  
      ond = t - ond;
      if(ond < 0) ond *= -1;
      if(ond < ans) ans = ond; 
    }

  printf("%.10lf\n",ans);

  return 0 ;
}
