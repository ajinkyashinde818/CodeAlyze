#include <bits/stdc++.h>
const int N=1005;
using namespace std;
typedef long double ld;
typedef long long ll;
vector<vector<ll>>ps;
ll n,x,y;
ld dist[N][N];
ld calc(vector<ll>&a,vector<ll>&b){
    ld x=a[0]-b[0];
    ld y=a[1]-b[1];
    ld e=x*x+y*y;
    e=max(e,(ld) 0.0);
    e=pow(e,0.5);
    e=max(e-a[2]-b[2],(ld) 0.0);
    return e;
}
vector<ld>d(N,numeric_limits<ld>::max());
int main()
{ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>x>>y;
    ps.push_back({x,y,0});
    cin>>x>>y;
    ps.push_back({x,y,0});
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x,y,r;cin>>x>>y>>r;
        ps.push_back({x,y,r});
    }
    for(int i=0;i<ps.size();i++){
        for(int j=0;j<ps.size();j++){
            dist[i][j]=calc(ps[i],ps[j]);
            //cout<<i<<' '<<j<<' '<<dist[i][j]<<endl;
        }
    }
    priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>>pq;
    pq.push({0,0});
    d[0]=0;
    while(pq.size()){
        int u=pq.top().second;pq.pop();
        //cout<<u<<' '<<d[u]<<endl;
        for(int v=0;v<ps.size();v++){
            if(d[u]+dist[u][v]<d[v]){
                d[v]=d[u]+dist[u][v];
                pq.push({d[v],v});
            }
        }
    }
    cout.precision(10);
    cout<<fixed<<d[1]<<'\n';
    return 0;
}
