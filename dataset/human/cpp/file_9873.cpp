#include <bits/stdc++.h>
using namespace std;

int n,s[100010][27],a[100010];
char ss[100010];
long long ans;
const long long mod=1e9+7;
int main()
{
	scanf("%d",&n);
	scanf("%s",ss+1);
	for(int i=1;i<=n;++i)
	a[i]=ss[i]-'a'+1;
	for(int i=n;i>=1;--i)
	{
		for(int j=1;j<=26;++j)
		s[i][j]=s[i+1][j];
		s[i][a[i]]++;
	}
	for(int i=1;i<=n;++i)
	{
		int x=a[i];
		long long res=1;
		for(int j=1;j<=26;++j)
		{
			if(j==x)
			continue;
			res=res*(s[i][j]+1)%mod;
		}
		ans=(ans+res)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
