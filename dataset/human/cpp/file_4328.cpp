#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<algorithm>
#define ll long long
using namespace std;
 
const int maxn = 210000;
 
int n;
int fa[maxn],s[maxn];
int findfa(const int x){ return fa[x]==x?x:fa[x]=findfa(fa[x]);}
 
struct node{int x,p,i;}a[maxn],b[maxn];
inline bool cmpx(const node x,const node y){return x.x<y.x;}
inline bool cmpi(const node x,const node y){return x.i<y.i;}
 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i].x); a[i].i=i;
		a[0].x^=a[i].x;
	}
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&b[i].x); b[i].i=i;
		b[0].x^=b[i].x;
	}
	sort(a,a+n+1,cmpx); sort(b,b+n+1,cmpx);
	a[0].p=0;
	for(int i=0;i<=n;i++) 
	{
		if(a[i].x!=b[i].x) return puts("-1"),0;
		b[i].p=a[i].p=a[i-1].p+(a[i].x!=a[i-1].x?1:0);
	}
	sort(a,a+n+1,cmpi); sort(b,b+n+1,cmpi);
	
	for(int i=0;i<=n;i++) fa[i]=i;
	for(int i=0;i<=n;i++) if(a[i].p!=b[i].p) s[a[i].p]++;
	for(int i=0;i<=n;i++) if(a[i].p!=b[i].p)
	{
		int x=findfa(a[i].p),y=findfa(b[i].p);
		if(x!=y) fa[y]=x,s[x]+=s[y];
	}
	int re=0;
	if(a[0].p==b[0].p) re++;
	for(int i=0;i<=n;i++) if(findfa(i)==i)
		if(s[i]>1) re+=s[i]+(i==findfa(a[0].p)?0:1);
	if(re) re--;
	printf("%d\n",re);
	
	return 0;
}
