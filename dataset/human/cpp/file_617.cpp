#include <iostream>

using namespace std;

int main() {
  int ans = 0;
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  for(int r = 0; r <= 3000; r++) {
  	for(int g = 0; g <= 3000; g++) {
      if (r * R + g * G > N) break;
      if ((N - (r * R + g * G)) % B != 0) continue;
      ans++;
    }
  }
  cout << ans << endl;
}
