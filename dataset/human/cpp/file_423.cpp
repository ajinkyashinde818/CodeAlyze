#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int R, G, B, N;

int main() {
  cin >> R >> G >> B >> N;

  for (int a = 0; a <= 3000; a++) {
    for (int b = 0; b <= 3000; b++) {
      int tmp = R * a + G * b;
      if (tmp > N) continue;
      if (tmp == N) {
        cnt++;
        continue;
      }
      if ((N - tmp) % B == 0) {
        // aa
        cnt++;
      }
    }
  }

  cout << cnt << endl;
}
