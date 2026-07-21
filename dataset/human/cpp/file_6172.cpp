//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define mp make_pair
#define gc (c=getchar())
char readc()
{
	char c;
	while(gc<'-');
	return c;
}
int read()
{
    char c;
    while(gc<'-');
    if(c=='-')
    {
        int x=gc-'0';
        while(gc>='0')x=x*10+c-'0';
        return -x;
    }
    int x=c-'0';
    while(gc>='0')x=x*10+c-'0';
    return x;
}
#undef gc

const int N=2e5+5;
int n;s64 c;
s64 x[N],s[N];int v[N];
s64 ans=0;
void solve()
{
	priority_queue<s64>a,b;
	rep(i,n+1,n*2){x[i]=x[i-n]+c;v[i]=v[i-n];}
	rep(i,1,n*2)s[i]=s[i-1]+v[i];
	rep(i,n+1,n*2)a.push(-x[i]+s[i]);
	per(i,n,1)
	{
		a.push(-x[i]+s[i]);
		b.push(-x[n+i]+s[n+i]);
		while(!b.empty()&&a.top()==b.top()){a.pop();b.pop();}
		chmax(ans,a.top()+x[i]-s[i-1]-min(x[i],c-x[i]));
	}
}

int main()
{
	cin>>n>>c;
	rep(i,1,n)scanf("%lld%d",x+i,v+i);
	solve();
	rep(i,1,n)x[i]=c-x[i];
	reverse(x+1,x+n+1);
	reverse(v+1,v+n+1);
	solve();
	cout<<ans;
}
