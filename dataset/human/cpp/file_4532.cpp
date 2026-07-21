#include<bits/stdc++.h>
using namespace std;

int main(){
  int T, D, tA, tB, dA, dB;
  cin >> T >> D;
  cin >> tA >> tB;
  cin >> dA >> dB;
  double res = 1 << 10;
  for(int a = 0; a <= D; a += dA){
    for(int b = 0; b <= D - a; b += dB){
      if(a == 0 && b == 0){
        continue;
      }
      double tmp = ((double)(tA * a + tB * b)) / (a + b) - T;
      if(tmp < 0){
        tmp = -tmp;
      }
      if(res > tmp){
        res = tmp;
      }
    }
  }
  cout << res << endl;
  return 0;
}
