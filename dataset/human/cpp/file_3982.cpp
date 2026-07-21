#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long double,int> P;
long double a,b;
int n;
long double x[1005],y[1005],r[1005];
struct edge{
    int to;
    long double cost;
};
vector<edge> G[1005];
long double d[1005];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+(n+2),10000000000);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main(void){
    cin>>x[0]>>y[0]>>a>>b;
    cin>>n;
    x[n+1]=a; y[n+1]=b;
    r[0]=0; r[n+1]=0;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>r[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n+1;j++){
            long double t;
            if(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<(r[i]+r[j])){
                t=0;
            }else{
                t=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))-(r[i]+r[j]);
            }
            G[i].push_back(edge{j,t});
            G[j].push_back(edge{i,t});
        }
    }
    dijkstra(0);
    cout<<setprecision(22)<<d[n+1]<<endl;

}
