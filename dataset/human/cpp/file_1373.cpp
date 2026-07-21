#include <bits/stdc++.h>
using namespace std;

int R, G, B, N;

int main() {
  cin >> R >> G >> B >> N;
  int res = 0;

  for(int x = 0; R*x <= N; x++) {
    for(int y = 0; R*x + G*y <= N; y++) {
      int z = (N - (R*x + G*y)) / B;
      if( (N - (R*x + G*y)) % B == 0 && z >= 0) {
        res++;
      }
    }
  }
  cout << res << endl;
}
