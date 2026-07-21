#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, cntneg = 0, minn = 1000000000;
  long long cnt = 0;
  bool haszero = false;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    if (a == 0) haszero = true;
    if (a < 0) {
      cntneg++;
      a *= -1;
    }
    minn = min(a, minn);
    cnt += a;
  }
  if (cntneg % 2 == 0 || haszero) minn = 0; 
  cout << cnt - 2 * minn << endl;
  return 0;
}
