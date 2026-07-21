#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> a;
  vector<string> b;
  for (int k = 0; k < n; k++)
  {
    string s;
    cin >> s;
    a.push_back(s);
  }
  for (int k = 0; k < m; k++)
  {
    string s;
    cin >> s;
    b.push_back(s);
  }

  bool ans = false;
  for (int i = 0; i < n - m + 1; i++)
  {
    for (int j = 0; j < n - m + 1; j++)
    {
      int count = 0;
      for (int k = 0; k < m; k++)
      {
        if (b.at(k) == a.at(i + k).substr(j, m))
        {
          count++;
        }
      }
      if (count == m)
      {
        ans = true;
        break;
      }
    }
    if (ans)
    {
      break;
    }
  }
  ans ? cout << "Yes" << endl : cout << "No" << endl;
}
