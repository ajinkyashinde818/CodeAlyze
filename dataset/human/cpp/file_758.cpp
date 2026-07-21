#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int c[3], N, ans = 0, c0, c1, c2, tmp, tmp1, tmp2;
  cin >> c[0] >> c[1] >> c[2] >> N;
  sort(c, c + 3);
  c2 = N / c[2];
  for(int i = 0; i <= c2; ++i) {
    tmp = N;
    tmp -= i * c[2];
    if(tmp == 0) {++ans; continue;}
    c1 = tmp / c[1];
    for(int j = 0; j <= c1; ++j) {
      tmp1 = tmp;
      tmp1 -= j * c[1];
      if(tmp1 == 0) {++ans; continue;}
      else if(tmp1 % c[0] == 0) ++ans;
    }
  }
  cout << ans << endl; 
}
