#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
double dist[1005],x[1005],y[1005],r[1005];
vector< pair<ll,double> >adj[1005];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>x[0]>>y[0]>>x[1]>>y[1];
    cin>>n;n+=2;
    for(ll i=2;i<n;i++)cin>>x[i]>>y[i]>>r[i];
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            double dist = hypot(x[i]-x[j],y[i]-y[j]) - r[i] - r[j];
            dist=max(dist , 0.0);
            adj[i].push_back({j,dist});
            adj[j].push_back({i,dist});
        }
        dist[i]=(1.0e+12);
    }
    priority_queue< pair<double,ll> > pq;
    pq.push({0,0});
    dist[0]=0;
    while(!pq.empty()){
        ll u = pq.top().second;
        pq.pop();
        for(auto &ele:adj[u]){
            if(dist[ele.first] > dist[u] + ele.second ){
                dist[ele.first] = dist[u] + ele.second;
                pq.push({-dist[ele.first] , ele.first});
            }
        }
    }
    cout<<fixed<<setprecision(18)<<dist[1];
}
