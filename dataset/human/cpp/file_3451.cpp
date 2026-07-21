#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n, 0);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  } 
  int minus = 0;
  for(int i = 0; i < n; i++) if(a[i] < 0) minus++;
  ll result = 0;
  for(auto e : a)
  {
    result += abs(e);
  }
  if(minus % 2 != 0)
  {
    ll smallest = abs(a.front());
    for(auto e : a)
    {
      smallest = min(smallest, abs(e));
    }
    result -= smallest * 2;
  }
  cout << result << endl;
}
