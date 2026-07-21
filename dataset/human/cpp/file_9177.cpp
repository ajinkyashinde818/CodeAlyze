#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  char a[51][51], b[51][51];
  for (int i = 0; i < n; i++)
  {
    scanf("%s", a[i]);
  }
  for (int j = 0; j < m; j++)
  {
    scanf("%s", b[j]);
  }
  bool flag = false;
  for (int i = 0; i <= n - m; i++)
  {
    for (int j = 0; j <= n - m; j++)
    {
      bool f = true;
      for (int k = 0; k < m; k++)
      {
        for (int l = 0; l < m; l++)
        {
          if (a[i + k][j + l] != b[k][l])
          {
            f = false;
            k = l = m;
          }
        }
      }
      if (f)
      {
        flag = true;
        i = j = n;
      }
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}
