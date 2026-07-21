#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  ll count = 0;
  for(int i = 0; i <= n; i++)
  {
    for(int j = 0; j <= n; j++)
    {
      int bz = n - r * i - g * j;
      if(bz % b != 0) continue;
      if(bz / b >= 0){
        count++;
      }
    }
  }
  cout << count << endl;
}
