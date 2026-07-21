#include<bits/stdc++.h>

using namespace std;


int main()
{
  int r, g, b, n;

  cin >> r >> g >> b >> n;

  int ret = 0;

  for(int i = n/r;
      i >= 0;
      --i)
    {
      if(i * r == n)
        {
          ++ret;
        }
      else
        {
          for(int j = (n - i*r)/g;
              j >= 0;
              --j)
            {
              if((i * r + j * g) == n)
                {
                  ++ret;
                }
              else
                {
                  if((n - i * r - j * g) % b == 0)
                    {
                      ++ret;
                    }
                }

            }
        }
    }
  cout << ret << endl;
  return 0;
}
