#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pa;
typedef unsigned int uint;
typedef unsigned long long ull;
#define w1 first
#define ls (x<<1)
#define w2 second
#define ins insert
#define rs (x<<1|1) 
#define mp make_pair
#define pb push_back
#define mid ((l+r)>>1)
#define sqr(x) ((x)*(x))
#define cle(x) ((x).clear())
#define lowbit(x) ((x)&(-x))
#define SZ(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()
#define ms(x,y) memset(x,y,sizeof (x))
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)]) 
#define Rep2(p,x) for(int (p)=cur[(x)];(p);(p)=nxt[(p)])
template<class T>inline void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
inline int getgcd(int x,int y){if(!x)return y;return getgcd(y%x,x);}
inline int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=(ll)x*x%p)if(k&1)res=(ll)res*x%p;return res;}
const double pi=acos(-1);	
inline void judge(){
	freopen("input.txt","r",stdin);
} 
//********************************head*************************************
const int maxn=1e5+5;
int n,ans;
int a[maxn],b[maxn],q1[maxn],q2[maxn];
map<int,int>occur,vis;
map<int,vector<int> >e;
void dfs(int x){
	vis[x]=1;
	rep2(i,0,SZ(e[x]))if(!vis[e[x][i]])dfs(e[x][i]);
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]),a[n+1]^=a[i];
	rep(i,1,n)read(b[i]),b[n+1]^=b[i];
	rep(i,1,n+1)q1[i]=a[i];sort(q1+1,q1+n+1+1);
	rep(i,1,n+1)q2[i]=b[i];sort(q2+1,q2+n+1+1);
	rep(i,1,n+1)if(q1[i]!=q2[i])return puts("-1"),0;
	rep(i,1,n)if(a[i]!=b[i])occur[a[i]]=occur[b[i]]=1,e[a[i]].pb(b[i]),ans++;
	occur[a[n+1]]=occur[b[n+1]]=1;
	if(!vis[b[n+1]])dfs(b[n+1]),ans++;
	rep(i,1,n)if(a[i]!=b[i]&&!vis[a[i]])dfs(a[i]),ans++;
	cout<<ans-1<<endl;
	return 0;
}
