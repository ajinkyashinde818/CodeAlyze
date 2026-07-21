#include <bits/stdc++.h>
using namespace std;

int main()
{
  int R, G, B, N;
  cin >> R >> G >> B >> N;

  int count = 0;
  for (double i = 0; i <= N; i++)
  {
    for (double j = 0; j <= N; j++)
    {
      double k = (N - R * i - G * j) / B;
      if (k >= 0 && floor(k) == k)
      {
        count++;
      }
    }
  }

  cout << count << endl;
}
