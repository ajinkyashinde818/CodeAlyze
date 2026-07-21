#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, G, B, N, count=0;
  cin >> R >> G >> B >> N;
  int r, g;
  for (r=0; r<=N/R; r++) {
    for (g=0; g<=N/G; g++) {
      if (N - R*r - G*g == 0) count++;
      else {
        if (N - R*r - G*g > 0) {
        int amari = (N - R*r - G*g) % B;
        if (amari == 0) count++;
        }
      }
    }
  }
  cout << count << endl;
}
