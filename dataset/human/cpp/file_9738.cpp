#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;


#define MOD (1000000000+7)


int main(void)
{
	int n;

	while(scanf("%d\n", &n)==1)
	{
		vector<char> s(n+2);
		vi c(26);

		scanf("%[a-z]", &s[0]);
		for(int i=0;i<n;i++)
		{
			c[s[i]-'a']++;
		}
		ll ans=1;
		for(int mc:c)
		{
			ans=(ans*(mc+1))%MOD;
		}
		printf("%lld\n", ans-1);
	}

	return 0;
}
