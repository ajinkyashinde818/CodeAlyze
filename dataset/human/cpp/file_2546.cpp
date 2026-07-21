#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  int count0 = 0;
  int countf = 0;
  long long ans = 0;
  for(i = 0; i < n; i++)
  {
    cin >> a.at(i);
    if(a.at(i) == 0) count0++;
    if(a.at(i) < 0) countf++;
  }
  if(count0 > 0 || countf%2==0)
  {
    for(i = 0; i < n; i++)
    {
      ans += abs(a.at(i));
    }
  }
  else
  {
    for(i = 0; i < n; i++)
    {
      a.at(i) = abs(a.at(i));
    }
    sort(a.begin(), a.end());
    ans -= a.at(0);
    for(i = 1; i < n; i++)
    {
      ans += abs(a.at(i));
    }
  }
  cout << ans << endl;
}
