#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;
  for (int rr = 0; rr < N/R+1; rr++) {
    for (int gg = 0; gg < (N-R*rr)/G+1; gg++) {
        if ((N-R*rr-G*gg)%B==0) ans++;
    }
  }
  cout << ans << endl;
}
