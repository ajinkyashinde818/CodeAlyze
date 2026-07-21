#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define m_p make_pair
#define sz(x) (int)x.size()
#define line cerr<<"--------------------\n";
#define see(x) cerr<<x<<" "
#define seeln(x) cerr<<x<<endl
#define out(x) cerr<<#x<<" = "<<x<<" "
#define outln(x) cerr<<#x<<" = "<<x<<endl
#define outarr(x,l,r) cerr<<#x"["<<l<<"-"<<r<<"] = "; for (int _i=l;_i<=r;++_i) cerr<<x[_i]<<" ";cerr<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define gc() getchar()
//char buf[1<<23],*p1=buf,*p2=buf;
//#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <class T> void read(T &x)
{
    x=0; char c=gc(); int flag=0;
    while (c<'0'||c>'9') flag|=(c=='-'),c=gc();
    while (c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=gc();
    if (flag) x=-x;
}
template <class T> inline T _max(T a,T b){return a>b ? a : b;}
template <class T> inline T _min(T a,T b){return a<b ? a : b;}
template <class T> inline bool checkmax(T &a,T b){return b>a ? a=b,1 : 0;}
template <class T> inline bool checkmin(T &a,T b){return b<a ? a=b,1 : 0;}
const int N=200005;
int n,a[N],b[N],vis[N];
void init()
{
	read(n);
	for (int i=1;i<=n;++i)
	{
		read(a[i]);
		vis[a[i]]++;
	}
	for (int i=1;i<=n;++i)
	{
		read(b[i]);
		vis[b[i]]++;
	}
}

void solve()
{
	for (int i=1;i<=n;++i)
	{
		if (vis[a[i]]>n||vis[b[i]]>n)
		{
			printf("No\n");
			return;
		}
	}
	reverse(b+1,b+n+1);
	int flag=0;
	multiset <int> S,T;
	for (int i=1;i<=n;++i)
	{
		if (a[i]==b[i])
		{
			flag=1;
			S.insert(i);
		}
	}
	if (!flag)
	{
		printf("Yes\n");
		for (int i=1;i<=n;++i)
		{
			printf("%d%c",b[i]," \n"[i==n]);
		}
		return;
	}
	int l=*S.begin(),r=*S.rbegin(),x=a[l];
	for (int i=1;i<=n;++i)
	{
		if (a[i]!=x&&b[i]!=x)
		{
			T.insert(i);
		}
	}
	for (int i=l;i<=r;++i)
	{
		int x=*T.begin();
		T.erase(T.begin());
		swap(b[x],b[i]);
	}
	printf("Yes\n");
	for (int i=1;i<=n;++i) printf("%d%c",b[i]," \n"[i==n]);
}

int main()
{
	init();
	solve();
	return 0;
}
