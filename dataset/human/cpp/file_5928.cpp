#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cctype>
#include<iomanip>
#include<string>
#include<utility>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define true false
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef queue<int> qi;
typedef queue<ll> ql;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define pq priority_queue
#define rep(i,n) for (int i=0;i<n;++i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define INF 1e15
#define init(x) memset(x,0,sizeof(x))

//  code begin here
ll n,c,ans=0;
ll v[100005],x[100005],vs[100005];
int main()
{
	ios::sync_with_stdio(true);
    cin>>n>>c;
	for (int i=1;i<=n;++i) cin>>x[i]>>v[i];
	ll cur=-INF,pos;
	for (int i=1;i<=n;++i){
		vs[i]=vs[i-1]+v[i];
		if (vs[i]-x[i]>cur){cur=vs[i]-x[i];pos=i;}
	}
	ans=max(ans,cur);
	ll bestadd=0;//best addition
	for (int i=n;i>pos;--i) bestadd=max(bestadd,vs[n]-vs[i-1]-2*(c-x[i]));
	for (int i=pos;i>0;--i){
		ans=max(ans,vs[i]-x[i]+bestadd);
		bestadd=max(bestadd,vs[n]-vs[i-1]-2*(c-x[i]));
	}
	for (int i=1;i<=n;++i) x[i]=c-x[i];
	reverse(x+1,x+n+1);reverse(v+1,v+n+1);reverse(vs+1,vs+n+1);
	cur=-INF;
	for (int i=1;i<=n;++i){
		vs[i]=vs[i-1]+v[i];
		if (vs[i]-x[i]>cur){cur=vs[i]-x[i];pos=i;}
	}
	ans=max(ans,cur);
	bestadd=0;//best addition
	for (int i=n;i>pos;--i) bestadd=max(bestadd,vs[n]-vs[i-1]-2*(c-x[i]));
	for (int i=pos;i>0;--i){
		ans=max(ans,vs[i]-x[i]+bestadd);
		bestadd=max(bestadd,vs[n]-vs[i-1]-2*(c-x[i]));
	}
	cout<<ans;
	return 0;
}
