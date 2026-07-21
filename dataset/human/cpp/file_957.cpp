#include <bits/stdc++.h>
using namespace std;

void ioinit() { ios::sync_with_stdio(0); cin.tie(0); }

int main() {
  ioinit();
  int R,G,B,N,sum=0;
  cin >> R >> G >> B >> N;
  for(int r = 0; r <= N/R; r++){
    for(int g = 0; g <= (N-R*r)/G; g++){
      if((N-r*R-g*G) % B == 0) sum++;
    }
  }
  cout << sum << endl;
}
