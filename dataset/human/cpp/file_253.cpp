//Rr+Gg+Bb==Nなる非負整数(r, g, b)の組を求める。
#include <bits/stdc++.h>
using namespace std;
int main()  {
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int ans = 0;
for (int i = 0; i <= 3000; i++)  {
  for (int j = 0; j <=3000; j++)  {
    int s = N - i*R - j*G;
    if( s>=0 && s<= 3000 && s%B==0) ++ans;
    }
  }

cout << ans << endl;

}
