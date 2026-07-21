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
using vc=vector<char>;

const ll MOD=1000000007;


ll frac(int n)
{
	ll ret=1;

	for(int i=1;i<=n;i++)
	{
		ret=(ret*i)%MOD;
	}
	return ret;
}


int main(void)
{
	int n;
	char s[200000+2];

	while(scanf("%d\n%200000[BW]\n", &n, s)==2)
	{
		vi a(2*n);
		vc c;
		char p='W';
		bool is_open=true;
		for(int i=0;i<2*n;i++)
		{
			a[i]=(s[i]=='B');
			if(p==s[i])
			{
				is_open=!is_open;
			}
			c.push_back(is_open?'(':')');
			p=s[i];
		}

//		printf("%.*s\n", c.size(), &c[0]);

		ll ans=frac(n);
		int o=0;
		for(int i=0;i<c.size();i++)
		{
			if(c[i]=='(')
			{
				o++;
				continue;
			}
			ans=(ans*o--)%MOD;
		}
		if(o!=0) ans=0;
		printf("%lld\n", ans);
	}
	return 0;
}
