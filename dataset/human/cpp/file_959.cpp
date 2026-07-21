#include <bits/stdc++.h>
using namespace std;

int main()
{
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  int cnt = 0;
  for (int r = 0; r <= N; r++)
  {
    for (int g = 0; g <= N; g++)
    {
      int b = (N - R * r - G * g) / B;
      if ((N - R * r - G * g) % B == 0 && b >= 0)
      {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
