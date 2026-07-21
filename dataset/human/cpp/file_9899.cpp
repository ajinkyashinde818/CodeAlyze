#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100005,MOD=1000000007;

char str[MAXN];
int cnt[30],ans=1,n;

int main()
{
	scanf("%d%s",&n,str);
	for(int i=0;i<n;i++)
		cnt[str[i]-'a']++;
	for(int i=0;i<30;i++)
		ans=1LL*ans*(cnt[i]+1)%MOD;
	ans=(ans-1+MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}
