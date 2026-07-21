#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
//#include <unordered_set>
//#include <unordered_map>
//#include <bits/stdc++.h>

#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define SIZE(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define fi first
#define se second
#define int ll

using namespace std;

template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod eps=1e-11;
const lod pi=acos(-1);
const int oo=1<<30;
const ll loo=1ll<<62;
const int mods=998244353;
const int MAXN=600005;
const int INF=0x3f3f3f3f;//1061109567
/*--------------------------------------------------------------------*/
inline int read()
{
	int f=1,x=0; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') f=-1; c=getchar(); }
	while (c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	return x*f;
}
PR p[MAXN];
int s[MAXN];
signed main()
{
	int n=read(),C=read(),ans=0;
	for (int i=1;i<=n;i++) p[i].fi=read(),p[i].se=read();
	for (int i=n;i>=1;i--) s[i]=s[i+1]+p[i].se;
	for (int i=n,smax1=0,smax2=0;i>=0;i--)
	{
		int t=(s[1]-s[i+1]);
		upmax(ans,t-p[i].fi);
		upmax(ans,t+smax1-p[i].fi*2);
		upmax(ans,t+smax2-p[i].fi);
		upmax(smax1,s[i]-(C-p[i].fi));
		upmax(smax2,s[i]-(C-p[i].fi)*2);
	}
	printf("%lld\n",ans);
	return 0;
}
