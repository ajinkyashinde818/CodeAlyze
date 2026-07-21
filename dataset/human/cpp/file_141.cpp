#include<bits/stdc++.h>
using namespace std;

int R, G, B, N;

int main() {
  cin >> R >> G >> B >> N;

  int cnt = 0;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) {
      if ((N - R * i - G * j) % B == 0 && (N - R * i - G * j) >= 0) cnt++;
    }
  }
  cout << cnt << endl;
}
