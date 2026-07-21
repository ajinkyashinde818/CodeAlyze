#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  	ll n;
  	cin>>n;
  	ll a[n], x = 0, y = 0, ans = INT_MAX;
  	for(int i = 0; i < n; i++)
    {
    	cin>>a[i];
      	x += a[i];
    }
  	for(int i = 0; i < n; i++)
    {
    	y += a[i];
      	if(i+1 < n)
          	ans = min(ans, abs(x-2*y));
    }
  	cout<<ans;
	return 0;
}
