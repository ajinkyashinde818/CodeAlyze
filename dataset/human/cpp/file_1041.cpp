#include<iostream>
using namespace std;
int main () {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
  for (int i = 0; i <= N; i ++) {
    for (int j = 0; j <= N; j ++) {
      int A = R * i + G * j;
      int n = N - A;
      //cout << n << endl;
      if (n >= 0 && n % B == 0) ans ++;
    }
  }
  cout << ans << endl;
}
