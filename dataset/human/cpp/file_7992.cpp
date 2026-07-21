#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector> 
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1000000000;
const int maxN = 100010;
int a[maxN*2];
ll abs_(ll x,ll y)
{
	ll z = x - y;
	if(z < 0)
		z = -z;
	return z;
}
int main()
{
	int n;
	scanf("%d",&n);
	ll ans = 0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans += a[i];
	}
	ll left=0,right=ans;
	ll minn = (ll)1<<50;
	ll cnt;
	for(int i=1;i<n;i++)
	{
		left+= a[i];
		right -= a[i];
		cnt = abs_(left,right);
		if(cnt < minn)
			minn = cnt; 
	}
	printf("%lld\n",minn);
	return 0;
}
