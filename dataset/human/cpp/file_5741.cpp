#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>

#define pb push_back
#define mp make_pair

using namespace std;

template<typename T>inline void upmin(T &x,T y) { y<x?x=y:0; }
template<typename T>inline void upmax(T &x,T y) { x<y?x=y:0; }

typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;

const int N=1e5+100;

LL gi() {
	LL w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}

//树高为i的树的sg为lowbit(i)
int lc[N],rc[N];bool die[N];
LL sg;
inline void dfs(int k,LL L) {
	if (!k) sg^=L&-L;
	else {
		if (die[k]) return;
		dfs(lc[k],L-1);
		dfs(rc[k],L-1);
	}
}
int main()
{
	int n=gi(),k,tot=1;char c;LL L=gi();
	while (n--) {
		while ((c=getchar())!='0'&&c!='1');
		for (k=1;c=='0'||c=='1';c=getchar())
			if (c=='0') {
				if (!lc[k]) lc[k]=++tot;
				k=lc[k];
			} else {
				if (!rc[k]) rc[k]=++tot;
				k=rc[k];
			}
		die[k]=true;
	}
	dfs(1,L+1);
	puts(sg?"Alice":"Bob");
	return 0;
}
