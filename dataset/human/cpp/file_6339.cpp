#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1e9+7;
const int N=1e5+3;

int n;
long long ans=1,sum;
char s[2*N];

int main() {
	scanf("%d",&n);n*=2;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if((sum&1)^(s[i]=='B'))
			sum++;
		else {
			ans=ans*sum%MOD;
			sum--;
		}
	if(sum!=0) ans=0;
	for(int i=n/2;i>=1;i--)
		ans=ans*i%MOD;
	printf("%lld\n",ans);
	return 0;
}
