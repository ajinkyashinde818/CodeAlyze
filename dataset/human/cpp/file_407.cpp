#include <bits/stdc++.h>
using namespace std;

int main()
{
  int R, G, B, N, count, ans;
  cin >> R >> G >> B >> N;

  for(int i = 0; i <= N / R; i++)
  {
    for(int j = 0; R * i + G * j <= N; j++)
    {
      for(int k = 0;  R * i + G * j + B * k <= N; k++)
      {
        ans = R * i + G * j + B * k;
      }
      if(ans == N)
      {
        count++;
      }
    ans = 0;
    }
  }
  cout << count << endl;
}
