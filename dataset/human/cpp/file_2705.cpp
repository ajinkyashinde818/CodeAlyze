#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll min(ll a, ll b)
{
  if(a<b) return a;
  return b;
}

int main()
{
  int n,m;
  cin >> n;
  m = pow(10,9);
  ll sum=0;
  ll count = 1;
  for(int i=0; i<n; i++)
  {
    ll tmp;
    cin >> tmp;
    sum += abs(tmp);
    m = min(m,abs(tmp));
    if(tmp<0) count*=-1;
  }
  count = count-1;
  cout << sum+count*m << endl;
  return 0;
}
