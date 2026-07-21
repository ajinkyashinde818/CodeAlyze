#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#include <bitset>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f3f3f3f3fLL
#define SIZE 8080
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;

typedef ll Weight;
struct Edge {
	int src, dst;
	Weight weight;
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
int N;
bool ans;
string str;
ll memor1[114514]={0};
ll memor2[114514]={0};
ll memol1[114514]={0};
ll memol2[114514]={0};
ll L;
int main(){
	
	cin>>N>>L;
	vector<pair<ll,ll> > sushi,sushirev;
	vector<ll> kyorir,kyoril;
	sushi.pb(mp((ll)0,(ll)0));
	kyorir.pb((ll)0);
	for(int i=0;i<N;i++){
		ll x,y;
		cin>>x>>y;
		sushi.pb(mp(x,y));
		kyorir.pb(x);
	}
	sushirev.pb(mp((ll)0,(ll)0));
	kyoril.pb((ll)0);
	for(int i=N;i>=1;i--){
		sushirev.pb(mp(L-sushi[i].first,sushi[i].second));
		kyoril.pb(L-sushi[i].first);
	}
	
	ll sum1=0,sum2=0;
	for(int i=1;i<=N;i++){
		ll nex=sushi[i].first,bex=sushi[i-1].first;
		ll cost=sushi[i].second;
		sum1+=cost-(nex-bex);
		sum2+=cost-(ll)2*(nex-bex);
		memor1[i]=max(memor1[i-1],sum1);
		memor2[i]=max(memor2[i-1],sum2);
	}
	
	sum1=0,sum2=0;
	for(int i=1;i<=N;i++){
		ll nex=sushirev[i].first,bex=sushirev[i-1].first;
		ll cost=sushirev[i].second;
		//cout<<nex<<" "<<bex<<endl;
		sum1+=cost-(nex-bex);
		sum2+=cost-(ll)2*(nex-bex);
		memol1[i]=max(memol1[i-1],sum1);
		memol2[i]=max(memol2[i-1],sum2);
		//cout<<memol1[i]<<" "<<memol2[i]<<endl;
	}
	ll ans=0;
	ans=max(memor1[N],memol1[N]);
	//cout<<ans<<endl;
	
	for(int i=1;i<=N;i++){
		ll now=kyorir[i];
		int ok=0,ng=N;
		while(ng-ok>1){
			int mid=(ng+ok)/2;
			if(kyoril[mid]<now){
				ok=mid;
			}else{
				ng=mid;
			}
		}
		//cout<<now<<" "<<min(ok,N-i)<<endl;
		ans=max(ans,memor1[i]+memol2[min(ok,N-i)]);
	}
	for(int i=1;i<=N;i++){
		ll now=kyoril[i];
		int ok=0,ng=N;
		while(ng-ok>1){
			int mid=(ng+ok)/2;
			if(kyorir[mid]<now){
				ok=mid;
			}else{
				ng=mid;
			}
		}
		ans=max(ans,memol1[i]+memor2[min(ok,N-i)]);
	}
	cout<<ans<<endl;
}
