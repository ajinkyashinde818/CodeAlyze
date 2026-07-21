#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<double, ll> P;
const double INF=2e18;
const double EPS=1e-10;
const ll MOD=1e9+7;
ll sx,sy,gx,gy;
ll N;
struct Circle{
    ll x,y;
    ll r;
}circle[1010];
struct Edge{
    ll to;
    double cost;
};
vector<Edge> edges[1010];
const ll S=1001;
const ll G=1002;
double minCost[1010];
int main(){
    cin>>sx>>sy>>gx>>gy>>N;
    for(ll i=0;i<N;i++){
        ll x,y,r;
        cin>>x>>y>>r;
        circle[i]=Circle{x,y,r};
    }
    double dist=hypot(sx-gx,sy-gy);
    //cout<<"s to g:"<<dist<<endl;
    edges[S].push_back(Edge{G,dist});
    for(ll i=0;i<N;i++){
        dist = max(0.0,hypot(circle[i].x-sx,circle[i].y-sy)-circle[i].r); 
        edges[S].push_back(Edge{i,dist});
        dist = max(0.0,hypot(circle[i].x-gx,circle[i].y-gy)-circle[i].r);
        edges[i].push_back(Edge{G,dist});
    }
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            dist = max(0.0,hypot(circle[i].x-circle[j].x,circle[i].y-circle[j].y)-circle[i].r-circle[j].r);
            edges[i].push_back(Edge{j,dist});
            edges[j].push_back(Edge{i,dist});
            // cout<<dist<<" ";
        }
        // cout<<endl;
    }

    priority_queue<P,vector<P>,greater<P> > pq;
    pq.push(P(0,S));
    minCost[S]=0;
    for(ll i=0;i<N;i++){
        minCost[i]=INF;
    }
    minCost[G]=INF;
    while(!pq.empty()){
        ll nowV=pq.top().second;
        double nowCost=pq.top().first;pq.pop();
        if(nowCost-EPS>minCost[nowV])continue;
        for(auto e:edges[nowV]){
            double newCost=minCost[nowV]+e.cost;
            if(newCost+EPS < minCost[e.to]){
                minCost[e.to]=newCost;
                pq.push(P(minCost[e.to],e.to));
            }
        }
    }
    cout<<setprecision(10)<<minCost[G]<<endl;
    return 0;
}
