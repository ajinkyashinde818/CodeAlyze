#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int T, D, t_A, t_B, d_A, d_B;
  cin >> T >> D >> t_A >> t_B >> d_A >> d_B;

  double ret = -1;
  for(int va=0;va<=D;va+=d_A){
	for(int vb=0;vb<=D-va;vb+=d_B){
	  if(va + vb < 1) continue;
	  double temp = (t_A * va + t_B * vb) * 1.0 / (va + vb);
	  ret = (ret < 0)? abs(temp-T): min(ret, abs(temp - T));
	}
  }

  printf("%.10f\n", ret);

  return 0;
}
