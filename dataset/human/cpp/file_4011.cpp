#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD=1000000007;
const ll INF=10000000100000;
const int MAX=100001;
const double EPS=1e-10;
struct edge{int to;double cost;};
typedef pair<double,int> P;
int V;
vector<edge> G[114514];
double d[114514];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>>que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first){
            continue;
        }
        for(int i=0;i<(int)G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
double dist(double x1,double y1,double r1,double x2,double y2,double r2){
    double res=max(0.0,sqrt(pow(x1-x2,2)+pow(y1-y2,2))-(r1+r2));
    return res;
}
int main() {
    double sx,sy,gx,gy;
    cin>>sx>>sy>>gx>>gy;
    int n;
    cin>>n;
    V=n+2;
    double x[1010],y[1010],r[1010];
    G[0].push_back({n+1,dist(sx,sy,0.0,gx,gy,0.0)});
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>r[i];
        G[0].push_back({i,dist(sx,sy,0.0,x[i],y[i],r[i])});
        G[i].push_back({n+1,dist(x[i],y[i],r[i],gx,gy,0.0)});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            G[i].push_back({j,dist(x[i],y[i],r[i],x[j],y[j],r[j])});
            G[j].push_back({i,dist(x[i],y[i],r[i],x[j],y[j],r[j])});
        }
    }
    dijkstra(0);
    printf("%.12lf\n",d[n+1]);
    return 0;
}
