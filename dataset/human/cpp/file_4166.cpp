#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

vector<double> dijkstra(vector<vector<pair<int,double>>>& graph,int s){
    int n=(int)graph.size();
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
    vector<double> dist(n,1e10);
    dist[s]=0;
    pq.push({0,s});
    while(pq.size()){
        auto p=pq.top();
        pq.pop();
        int v=p.second;
        if(dist[v]<p.first)continue;
        for(auto edge:graph[v]){
            int u=edge.first;
            double w=edge.second;
            if(dist[v]+w<dist[u]){
                dist[u]=dist[v]+w;
                pq.push({dist[u],u});
            }
        }
    }
    return dist;
}

int main(){
    int sx,sy,gx,gy,n;
    cin>>sx>>sy>>gx>>gy>>n;
    double x[n+2],y[n+2],r[n+2];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>r[i];
    }
    x[n]=sx,y[n]=sy,r[n]=0;
    x[n+1]=gx,y[n+1]=gy,r[n+1]=0;
    vector<vector<pair<int,double>>> g(n+2);
    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++){
            double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            g[i].push_back({j,max(0.0,d-r[i]-r[j])});
            g[j].push_back({i,max(0.0,d-r[i]-r[j])});
        }
    }
    vector<double> d=dijkstra(g,n);
    cout<<fixed<<setprecision(10)<<d[n+1]<<endl;
}
