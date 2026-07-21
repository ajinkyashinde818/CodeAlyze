#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MaxN = 55;

char a[MaxN][MaxN], b[MaxN][MaxN];

int n, m;

int check(int si, int sj)
{
   int i, j;
   for (i = 0; i < m; i++)
     for (j = 0; j < m; j++)
       if (a[i+si][j+sj] != b[i][j])
         return 0;
   return 1;
}

int main( void )
{
  int i, j;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    scanf (" %s", a[i]);
  for (i = 0; i < m; i++)
    scanf (" %s", b[i]);
  string ans = "No";
  for (i = 0; i + m <= n; i++)
    for (j = 0; j + m <= n; j++)
      if (check(i, j))
        ans = "Yes";
  cout << ans << endl;
  return 0;
}
