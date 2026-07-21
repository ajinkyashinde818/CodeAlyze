#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int main() {
	cout<<setiosflags(ios::fixed)<<setprecision(12);
    int xs,ys,xt,yt,n;cin>>xs>>ys>>xt>>yt>>n;
    vector<vector<pair<int,ld>>> edge(n+10);
    vector<pair<pii,int>> cir;
    cir.push_back({{ys,xs},0});
    cir.push_back({{yt,xt},0});
    auto pdis =[&](const pii& a,const pii&b) ->ld{
    	return sqrt(((ld)a.first-b.first)*(a.first-b.first)+(ld)(a.second-b.second)*(a.second-b.second)) ;
    };
    auto dis =[&](const pair<pii,int>& a,const pair<pii,int>& b)->ld {
    	ld pd=pdis(a.first,b.first);
    	return max((ld)0,pd-a.second-b.second);
    };
    for(int i=1;i<=n;i++) {
    	int x,y,r;cin>>x>>y>>r;
    	cir.push_back({{y,x},r});
    }
    for(int i=0;i<=n+1;i++) {
    	for(int j=i+1;j<=n+1;j++) {
    		ld ds=dis(cir[i],cir[j]);
    		edge[i].push_back({j,ds});
    		edge[j].push_back({i,ds});
    	}
    }
    vector<ld> ans(n+10,1e18);
    vector<bool> vis(n+10);
    auto dijkstra =[&](){
    	priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> PQ;
    	PQ.emplace(0,0);
    	while(!PQ.empty()) {
    		ld ds=PQ.top().first,u=PQ.top().second;PQ.pop();
    		if(vis[u]) continue;vis[u]=1;ans[u]=ds;
    		for(auto e:edge[u]) {
    			int v=e.first;
    			if(vis[v]||ans[v]<ans[u]+e.second) continue;
    			PQ.emplace(ans[u]+e.second,v);
    		}
    	}
    };
    dijkstra();
    cout<<ans[1]<<endl;
    return 0;
}
