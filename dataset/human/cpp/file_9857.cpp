//Zory-2019
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<algorithm>
#include<iostream>
#include<deque>
using namespace std;
namespace mine
{
	typedef long long ll;
	#define double long double
	const int INF=0x3f3f3f3f;
	ll qread()
	{
		ll ans=0;char c=getchar();int f=1;
		while(c<'0' or c>'9') {if(c=='-') f=-1;c=getchar();}
		while('0'<=c and c<='9') ans=ans*10+c-'0',c=getchar();
		return ans*f;
	}
	void write(ll num)
	{
		if(num<0) {num=-num;putchar('-');}
		if(num>9) write(num/10);
		putchar('0'+num%10);
	}
	void writeln(int num){write(num);puts("");}
	#define FR first
	#define SE second
	#define MP make_pair
	#define pr pair<ll,ll>
	#define PB push_back
	inline void chmax(ll &x,ll y) {x=x>y?x:y;}
	inline void chmin(ll &x,ll y) {x=x<y?x:y;}

	const int MOD=1e9+7;
	const int MAX_N=1e5+10;
	char s[MAX_N];
	int f[30];
	void main()
	{
		int n;scanf("%d",&n);
		scanf("%s",s+1);for(int i=1;i<=n;i++) f[s[i]-'a']++;
		ll ans=1;for(int i=0;i<26;i++) ans=ans*(f[i]+1)%MOD;
		printf("%lld",(ans+MOD-1)%MOD);
 	}
};
int main()
{
	srand(time(0));
	mine::main();
}
