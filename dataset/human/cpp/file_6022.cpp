#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<functional>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X <<":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
const ll INF = 9e14;
typedef std::pair<int,int> P;
struct edge{ int to,cost; };
#define VMAX 100000
//bool cmp(P a,P b){ return a.second < b.second;}

ll N,M,K,ans=0;
ll C;
ll X[100010],V[100010];
ll dis[100010],va[100010];
ll rdis[100010],rva[100010];
unordered_map<ll,ll> Q;
int main(){
	std::ios_base::sync_with_stdio(false);
	cin>>N>>C;
	REP(i,N){
		cin>>X[i]>>V[i];
		rdis[N-1-i]=C-X[i];
		dis[i]=X[i];
		rva[N-1-i]=va[i]=V[i];
	}
	REP(i,N){rva[i+1]+=rva[i];va[i+1]+=va[i];}
//	REP(i,N){DEB(dis[i])DEB(va[i])DEB(rdis[i])DEB(rva[i])END}
	REP(k,2){
		ll temp=0,buff=0;
		if(k==0){
			REP(i,N+1){
				if(i==0){temp=rva[N-1]-rdis[N-1]*2;}
				else{
					buff=max(buff,va[i-1]-dis[i-1]);
					if(i==N)temp=max(temp,buff);
					else temp=max(temp,rva[N-1-i]-rdis[N-1-i]*2+buff);
				}
			}
			ans=max(temp,ans);
		}else{
			REP(i,N+1){
				if(i==0)temp=va[N-1]-dis[N-1]*2;
				else{
					buff=max(buff,rva[i-1]-rdis[i-1]);
					if(i==N)temp=max(temp,buff);
					else temp=max(temp,va[N-1-i]-dis[N-1-i]*2+buff);
				}
			}
			ans=max(temp,ans);
		}
	}

	cout<<ans<<endl;
	return 0;
}
