#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;

  int open = 0;
  long long ans = 1;
  for (int i = 0; i < n * 2; i++)
    if ((s[i] == 'B') ^ (open % 2)) open++;
    else ans = ans * (open--) % BASE;

  for (int i = 2; i <= n; i++)
    ans = ans * i % BASE;

  cout << (open ? 0 : ans) << endl;
}
