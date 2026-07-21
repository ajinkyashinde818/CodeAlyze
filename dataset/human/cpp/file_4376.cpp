#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n;
int a[100010];
int b[100010];

const int inf = 1e9;

bool val(){
	vector<int> vx, vy;
	for(int i=1; i<=n+1; ++i){
		vx.pb(a[i]); vy.pb(b[i]);
	}
	sort(all(vx)); sort(all(vy));
	for(int i=0; i<=n; ++i) if(vx[i] != vy[i]) return 0;
	return 1;
}

int cn;
void comp(){
	vector<int> xp;
	for(int i=1; i<=n+1; ++i) xp.pb(a[i]), xp.pb(b[i]);
	sort(all(xp));
	xp.erase(unique(all(xp)), xp.end());
	cn = xp.size();
	for(int i=1; i<=n+1; ++i){
		a[i] = lower_bound(all(xp), a[i]) - xp.begin();
		b[i] = lower_bound(all(xp), b[i]) - xp.begin();
	}
}

int par[100010];
int r(int x){ return (par[x]==x)?x:(par[x]=r(par[x])); }
void join(int a, int b){ par[r(a)]=r(b); }
bool ex[100010];

bool vis[100010];

int main()
{
	read(n);
	for(int i=1; i<=n; ++i) read(a[i]);
	for(int i=1; i<=n; ++i) read(b[i]);
	int x=0, y=0;
	for(int i=1; i<=n; ++i){
		x^=a[i]; y^=b[i];
	}
	a[n+1]=x; b[n+1]=y;
	comp();
	
	if(!val()){
		puts("-1");
		return 0;
	}
	
	for(int i=0; i<cn; ++i) par[i]=i;
	int df = 0;
	for(int i=1; i<=n; ++i){
		if(a[i] != b[i]){
			ex[a[i]]=1; ex[b[i]]=1;
			join(a[i], b[i]);
			++df;
		}
	}
	
	ex[a[n+1]]=1; ex[b[n+1]]=1;
	int comp = 0;
	for(int i=0; i<cn; ++i){
		if(!ex[i]) continue;
		if(vis[r(i)]) continue;
		++comp; vis[r(i)]=1;
	}
	
	printf("%d\n", df + comp - 1);
	return 0;
}
