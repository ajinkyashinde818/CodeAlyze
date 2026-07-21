#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  int all;

  for (int i = 0; i <= N / R; i++) {
    for (int j = 0; j <= N / G; j++) {
      all = N;
      all -= i * R + j * G;
      if (all < 0) break;
      if (all % B == 0) ans++;
    }
  }
  cout << ans << endl;
}
