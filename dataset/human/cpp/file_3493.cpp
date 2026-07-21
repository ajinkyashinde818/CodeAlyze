#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <cstdint>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int64_t a[n];
  for(int i = 0;
      i < n;
      ++i)
    {
      cin >> a[i];
    }

  int64_t sum = 0;
  for(int i = 0;
      i < n;
      ++i)
    {
      if(a[i] == 0)
        {
          for(int i = 0;
              i < n;
              ++i)
            {
              sum += abs(a[i]);
            }
          cout << sum << endl;
          return 0;
        }
    }

  sum = 0;

  for(int i = 0;
      i < n - 1;
      ++i)
    {
      if(a[i] < 0)
        {
          a[i] = -a[i];
          a[i + 1] = -a[i + 1];
        }
    }

  if(a[n - 1] < 0)
    {
      int min = 1000000000;
      int min_pos = 0;
      for(int i = 0;
          i < n;
          ++i)
        {
          if(abs(a[i]) < min)
            {
              min = abs(a[i]);
              min_pos = i;
            }
        }
      for(int i = 0;
          i < n;
          ++i)
        {
          if(i != min_pos)
            sum += abs(a[i]);
          else
            sum += -abs(a[i]);
        }
      cout << sum << endl;
    }
  else
    {
      for(int i = 0;
          i < n;
          ++i)
        {
          sum += a[i];
        }
      cout << sum << endl;
    }

  return 0;
}
