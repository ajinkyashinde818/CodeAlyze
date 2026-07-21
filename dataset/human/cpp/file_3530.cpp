#include <bits/stdc++.h>

using namespace std;


int main(){
  int N;
  cin >> N;
  long long ans=0;
  long long minval=1e10;
  int coef = 0;
  for(int i=0;i<N;i++){
    long long tmp;
    cin >> tmp;
    coef = tmp<0 ? 2-coef: coef;
    tmp = abs(tmp);
    minval = min(minval, tmp);
    ans += tmp;
  }

  cout << ans - coef*minval;
  return 0;
}
