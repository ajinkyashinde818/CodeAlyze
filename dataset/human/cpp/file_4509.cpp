#include<bits/stdc++.h>
using namespace std;

int main()
{
  int T, D;
  int tA, tB, dA, dB;

  cin >> T >> D;
  cin >> tA >> tB;
  cin >> dA >> dB;

  double ret = 1e9;
  for(int A = 0; A <= D; A += dA) {
    for(int B = 0; A + B <= D; B += dB) {
      if(A == 0 && B == 0) continue;
      ret = min(ret, fabs(T - (double)(tA * A + tB * B) / (A + B)));
    }
  }
  cout << fixed << setprecision(10) << ret << endl;
  return(0);
}
