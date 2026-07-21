#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> pllpl;
typedef pair<int,double> pid;
typedef pair<double,int> pdi;

const double INF = 1e18;

inline ll sq(ll x){
	return x*x;
}

vector<pllpl> titik;
vector<pid> adj[1010];

void make_edge(int x, int y){
	double jar = sqrt(sq(titik[x].first.first - titik[y].first.first) + sq(titik[x].first.second - titik[y].first.second));
	jar -= titik[x].second + titik[y].second;
	jar = max(0.00,jar);
	adj[x].push_back(make_pair(y,jar));
	adj[y].push_back(make_pair(x,jar));
	return ;
}

double jar[1010];

double dijk(int x, int y){
	for(int i=1;i<=y;i++) jar[i] = INF;
	priority_queue<pdi> pq;
	jar[x] = 0.00;
	pq.push(make_pair(0.00,x));
	while(!pq.empty()){
		pdi cur = pq.top(); pq.pop();
		if(cur.second == y) return fabs(cur.first);
		if(jar[cur.second] < -cur.first) continue;
		int now = cur.second;
		double tmp = cur.first;
		for(int i=0;i<adj[now].size();i++){
			int skrg = adj[now][i].first;
			double tmpj = tmp-adj[now][i].second;
			if(jar[skrg] <= -tmpj) continue;
			jar[skrg] = -tmpj;
			pq.push(make_pair(tmpj,skrg));
		}
	}
	return -1;
}

int n;

int main(){
	pll a,b;
	scanf("%lld%lld%lld%lld",&a.first,&a.second,&b.first,&b.second);
	titik.push_back(make_pair(a,0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		titik.push_back(make_pair(make_pair(x,y),z));
	}
	titik.push_back(make_pair(b,0));
	for(int i=0;i<titik.size();i++){
		for(int j=i+1;j<titik.size();j++){
			make_edge(i,j);
		}
	}
	double ans = dijk(0,titik.size()-1);
	printf("%.10lf\n",ans);
	return 0;
}///
