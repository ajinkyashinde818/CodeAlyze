// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,x[1111],y[1111],r[1111];
double dis[1111][1111],dist[1111];
bool vis[1111];
void dijkstra(int s)
{
	for(int i=1;i<=n;i++)dist[i]=1e100;
	dist[s]=0.0;
	for(int _=1;_<=n;_++)
	{
		int x=0;for(int i=1;i<=n;i++)if(!vis[i]&&(x==0||dist[i]<dist[x]))x=i;
		if(x==0)break;
		vis[x]=1;
		for(int i=1;i<=n;i++)dist[i]=min(dist[i],dist[x]+dis[x][i]);
	}
}
int main()
{
	get2(x[1],y[1]);get2(x[2],y[2]);get1(n);
	for(int i=3;i<=n+2;i++)get3(x[i],y[i],r[i]);n+=2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j])<=1ll*(r[i]+r[j])*(r[i]+r[j]))dis[i][j]=0.0;
			else dis[i][j]=sqrt(1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]))-r[i]-r[j];
		}
	}
	dijkstra(1);
	printf("%.10lf\n",dist[2]);
	return 0;
}
