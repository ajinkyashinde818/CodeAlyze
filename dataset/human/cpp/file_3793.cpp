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
const int N=100000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u];i;i=sq[i].nxt)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
int n;
struct point{double x,y;}st,ed;
struct circle{point p;double r;}cir[1010];
struct node{int to,nxt;double cost;}sq[2002000];
int all=0,head[1010];
double dis[1010];
bool vis[1010];
struct hnode{int u;double dis;};
bool operator <(hnode p,hnode q) {return p.dis>q.dis;}
priority_queue<hnode> q;

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

void add(int u,int v,double w)
{
	all++;sq[all].to=v;sq[all].nxt=head[u];sq[all].cost=w;head[u]=all;
}

double calc(point a,point b)
{
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

int main()
{
	st.x=read();st.y=read();ed.x=read();ed.y=read();
	n=read();
	rep(i,1,n) 
	{
		cir[i].p.x=read();cir[i].p.y=read();cir[i].r=read();
	}
	cir[++n]=(circle){st,0};
	cir[++n]=(circle){ed,0};
	rep(i,1,n) rep(j,i+1,n)
	{
		double dis=calc(cir[i].p,cir[j].p)-cir[i].r-cir[j].r;
		dis=max(dis,0.0);
		add(i,j,dis);add(j,i,dis);
	}
	rep(i,1,n) dis[i]=1e18;
	dis[n-1]=0;q.push((hnode){n-1,0});
	while (!q.empty())
	{
		int u=q.top().u;q.pop();
		if (vis[u]) continue;vis[u]=1;
		go(u,i)
		{
			int v=sq[i].to;
			if (dis[v]>dis[u]+sq[i].cost)
			{
				dis[v]=dis[u]+sq[i].cost;
				if (!vis[v]) q.push((hnode){v,dis[v]});
			}
		}
	}
	printf("%0.10lf",dis[n]);
	return 0;
}
