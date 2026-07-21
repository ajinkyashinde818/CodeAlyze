#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);
  int i, j, p, q;
  for(i = 0; i < n; i++)
  {
    cin >> a.at(i);
  }
  for(i = 0; i < m; i++)
  {
    cin >> b.at(i);
  }
  int check = 0;
  int s = 0;
  p = 0;
  q = 0;
  while(q <= n-m)
  {
    for(i = 0; i < m; i++)
    {
      for(j = 0; j < m; j++)
      {
        if(a.at(i+p).at(j+q)==b.at(i).at(j))
        {
          check++;
        }
      }
    }
    if(check == m*m)
    {
      s = 1;
      break;
    }
    else
    {
      check = 0;
      p++;
      if(p > n-m)
      {
        p = 0;
        q++;
      }
    }
  }
  if(s == 1)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
