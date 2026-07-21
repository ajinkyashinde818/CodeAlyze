#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef pair<ll,ld> pd;
typedef pair<ld,ll> pdi;

typedef vector <pd> vpi;
typedef pair<pi,ll> pii;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 1010
#define int ll

pi st,e;
int N;

pii points[maxn];

ld cirtocir(pii c1,pii c2){
	int dist = (c1.f.f - c2.f.f)*(c1.f.f - c2.f.f) + (c1.f.s - c2.f.s) * (c1.f.s - c2.f.s);
	
	ld d = sqrt(dist);
	
	return max((ld)0,d - c1.s - c2.s);
}

ld ptop(pi p1,pi p2){
	int dist = (p1.f - p2.f)*(p1.f - p2.f) + (p1.s - p2.s) * (p1.s - p2.s);
	
	return sqrt(dist);
}

ld ptocir(pi p1,pii c2){
	int dist = (p1.f - c2.f.f)*(p1.f - c2.f.f) + (p1.s - c2.f.s) * (p1.s - c2.f.s);
	
	return max((ld)0,(ld)sqrt(dist) - c2.s);
}
	
	
vpi adj[maxn];
ld dist[maxn];

int32_t main(){
	fast;
	
  	cout<<setprecision(10);
	cin>>st.f>>st.s>>e.f>>e.s;
	cin>>N;
	
	FOR(i,1,N){
		cin>>points[i].f.f>>points[i].f.s>>points[i].s;
	}
	
	FOR(i,0,N+1){
		FOR(j,i+1,N+1){
			ld dist;
			if (i == 0 && j == N+1) dist = ptop(st,e);
			else if (i == 0) dist = ptocir(st,points[j]);
			else if (j == N+1) dist = ptocir(e,points[i]);
			else dist = cirtocir(points[i],points[j]);
			
			//cout<<i<<' '<<j<<' '<<dist<<'\n';
			adj[i].pb(pd(j,dist));
			adj[j].pb(pd(i,dist));
		}
	}
	
	priority_queue <pdi,vector <pdi>, greater <pdi> > pq;
	
	pq.push(pdi(0,0));
	
	FOR(i,0,N+1) dist[i] = -1;
	dist[0] = 0;
	
	while (!pq.empty()){
		pdi cur = pq.top(); pq.pop();
		//cout<<cur.f<<' ';
		
		if (dist[cur.s] != cur.f) continue;
		
		aFOR(i,adj[cur.s]){
			if (dist[i.f] == -1 || dist[i.f] > cur.f + i.s){
				dist[i.f] = cur.f + i.s;
				pq.push(pdi(dist[i.f],i.f));
			}
		}
	}
	
	cout<<dist[N+1];
	
	
}
