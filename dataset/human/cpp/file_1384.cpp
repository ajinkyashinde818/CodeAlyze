#include <iostream>
using namespace std;

int main()
{
  int r, g, b, n, i, j;
  cin >> r >> g >> b >> n;
  int cnt = 0;
  for (i = 0; r * i <= n; i++) {
    for (j = 0; b * j <= n; j++) {
      if (n-r*i-b*j>=0 && (n-r*i-b*j)%g==0)
        cnt++;
    }
  }
  cout << cnt << endl;
}
