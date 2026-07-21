#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;


int main(void)
{
	int n;

	while(scanf("%d", &n)==1)
	{
		vi a(n);
		int minus=0;
		int abs_min=2000000000;
		ll ans=0;

		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			if(a[i]<0) minus++;
			ans+=abs(a[i]);
			if(abs_min>abs(a[i])) abs_min=abs(a[i]);
		}
		if(minus&1) ans-=abs_min*2;
		printf("%lld\n", ans);
	}
	return 0;
}
