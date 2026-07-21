#include<bits/stdc++.h>
using namespace std;

int main()
{
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int i, j;
  int count = 0;
  for(i = 0; i <= n/r; i++)
  {
    for(j = 0; j <= (n-i*r)/g; j++)
    {
      if((n-(i*r+j*g)) % b == 0)
      {
        count++;
      }
    }
  }
  cout << count << endl;
}
