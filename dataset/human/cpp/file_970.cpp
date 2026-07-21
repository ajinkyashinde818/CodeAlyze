#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int R, G, B, N, r, g, b, ans = 0;
   cin >> R >> G >> B >> N;

   for (int r = 0; r <= N / R; r++) {
     for (int g = 0; g <= (N - r * R) / G; g++) {
        if ((N - (R * r + G * g)) % B == 0) ans++;
     }
   }
   cout << ans << endl;
  }
