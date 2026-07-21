#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e5+5;
const int mo=1e9+7;
int n,x,ans,a[26];
char s[N];
int main()
{
	scanf("%d\n",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
	{
		x=s[i]-'a';
		a[x]++;
	}
	ans=1;
	for (int i=0;i<=26;i++) ans=(long long)ans*(a[i]+1)%mo;
	ans=(ans-1+mo)%mo;
	printf("%d",ans);
	return 0;
}
