#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5 + 10;
int n;
long long a[maxn];
int main()
{
	cin>>n;
	long long ans = 0, mx = -1e18, mn = 1e18;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		ans += abs(a[i]);
		if(a[i] < 0)
		{
			cnt++;
			mx = max(mx, a[i]);
		}
		else
			mn = min(mn, a[i]);
	}
	cout<<ans - (cnt & 1 ? min(-mx, mn) : 0ll) * 2ll<<endl;
	return 0;
}
