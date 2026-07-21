#include <iostream>

using namespace std;

int main()	{
  char a[55][55];
  char b[55][55];
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++)
      cin >> b[i][j];
  bool found = false;
  for (int i = 0; i <= n - m; i++)	{
    for (int j = 0; j <= n - m; j++)	{
      for (int x = i; x < i + m; x++)	{
        for (int y = j; y < j + m; y++)	{
          if (a[x][y] == b[x - i][y - j])
            found = true;
          else	{
            found = false;
            break;
          }
        }
        if (!found) break;
      }
      if (found == true)	{
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
