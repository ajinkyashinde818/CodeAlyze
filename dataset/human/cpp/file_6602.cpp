#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 1000000007
#define eps 1e-8
int n,op[200200];
char s[200200];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int main()
{
	n=read();scanf("%s",s+1);
	rep(i,1,n+n)
	{
		if ((i&1)^(s[i]=='B')) op[i]=-1;
		else op[i]=1;
	}
	//rep(i,1,n*2) cout << op[i] << " ";cout << endl;
	int now=0;ll ans=1;
	rep(i,1,n*2)
	{
		if (op[i]==-1)
		{
			if (!now) {puts("0");return 0;}
			ans=ans*now%maxd;
		}
		now+=op[i];
	}
	if (now) {puts("0");return 0;}
	rep(i,1,n) ans=ans*i%maxd;
	printf("%lld",ans);
	return 0;
}
