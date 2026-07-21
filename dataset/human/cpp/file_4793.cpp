#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	long long int n, r;
   cin>>n>>r;
  if (n >= 10)
	cout<<r<<"\n";
  else 
    cout<<(r + 100*(10-n))<<"\n";
  return 0;
}
