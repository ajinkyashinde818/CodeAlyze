#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<double> vec;
typedef vector<vector<ll>> mat;
typedef pair<double,int> P;

struct edge{int to;double cost;};
double INF=1.0e15;

int N;
//隣接リスト
vector<vector<edge>> G;

double dijkstra(){
    priority_queue<P,vector<P>,greater<P>> que;
    vec d(N+2,INF);d[0]=0.0;
    que.push(P(0.0,0));

    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(auto e:G[v]){
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    return d[N+1];
}

int main(){
    double xs,ys,xt,yt;cin>>xs>>ys>>xt>>yt>>N;
    vec x(N+1),y(N+1),r(N+1);
    for(int i=1;i<=N;i++) cin>>x[i]>>y[i]>>r[i];
    G.resize(N+2);
    G[0].push_back((edge){N+1,sqrt((xs-xt)*(xs-xt)+(ys-yt)*(ys-yt))});
    for(int i=1;i<=N;i++){
        double d=sqrt((x[i]-xs)*(x[i]-xs)+(y[i]-ys)*(y[i]-ys));
        if(d<r[i]) G[0].push_back((edge){i,0.0});
        else       G[0].push_back((edge){i,d-r[i]});
    }
    for(int i=1;i<=N;i++){
        double d=sqrt((x[i]-xt)*(x[i]-xt)+(y[i]-yt)*(y[i]-yt));
        if(d<r[i]) G[i].push_back((edge){N+1,0.0});
        else       G[i].push_back((edge){N+1,d-r[i]});
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            if(r[i]+r[j]>d){
                G[i].push_back((edge){j,0.0});
                G[j].push_back((edge){i,0.0});
            }
            else{
                G[i].push_back((edge){j,d-r[i]-r[j]});
                G[j].push_back((edge){i,d-r[i]-r[j]});           
            }
        }
    }
    printf("%.10lf\n",dijkstra());
    return 0;
}
