#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

int main()
{
  int N, R, ans = 0;
  cin >> N >> R;
  if (N >= 10)
  {
    ans = R;
  }
  else
  {
    ans = R + 100 * (10 - N);
  }

  cout << ans << endl;
  return 0;
}
