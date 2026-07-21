#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int n;
ll c;
ll a[100005];
ll v[100005];
ll m[100005];
set <ll> squ;
ll maxn;

void func()
{
	memset(m,0,sizeof(m));
	ll now=0;
	for(int i=0;i<n;i++)
	{
		now+=v[i];
		m[i]=max(now-a[i],(i-1<0?0:m[i-1]));
	}
	maxn=max(maxn,m[n-1]);
	ll d=0;
	now=0;
	for(int i=n-1;i>=0;i--)
	{
		d=c-a[i];
		now+=v[i];
		maxn=max(maxn,now-d-d+(i-1<0?0:m[i-1]));
		maxn=max(maxn,now-d);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",a+i,v+i);
	}
	ll now=0;
	for(int i=n-1;i>=0;i--)
	{
		now+=v[i];
		m[i]=max(now-(c-a[i]),m[i+1]);
//		if(now-(c-a[i])) squ.insert(i);
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<m[i]<<endl;
//	}
	maxn=m[0];
	ll d=0;
	now=0;
	for(int i=0;i<n;i++)
	{
		d=a[i];
		now+=v[i];
//		cout<<now<<' '<<now-d-d+m[i+1]<<endl;
		maxn=max(maxn,now-d-d+m[i+1]);
		maxn=max(maxn,now-d);
//		maxn=max(maxn,now);
	}
	func();
	cout<<maxn<<endl;
	return 0;
}
