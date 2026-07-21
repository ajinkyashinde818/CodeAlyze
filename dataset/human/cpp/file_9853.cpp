#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD=1e9+7;
int n;
int sum[30];
char s[100005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		sum[s[i]-'a']++;
	}
	long long ans=1;
	for(int i=0;i<26;i++)
	{
		ans=(ans*(sum[i]+1))%MOD;
	}
	ans--;
	ans=(ans%MOD+MOD)%MOD;
	printf("%lld\n",ans);
}
