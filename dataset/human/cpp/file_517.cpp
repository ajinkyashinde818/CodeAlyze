#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int ans = 0;

  for(int r=0;R*r<=N;r++) {
    for(int g=0;R*r+G*g<=N;g++) {
      if((N - R * r - G * g) % B == 0) ans++;
    }
  }

  cout << ans << endl;
}
