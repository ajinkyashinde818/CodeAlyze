#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<iomanip>
using namespace std;

const int MAX_V=1010;//頂点数の最大値
const double INF=999999999999.9;
double cost[MAX_V][MAX_V];//cost[u][v]は辺e=(u,v)のコスト、辺が無い場合はINF
double d[MAX_V];//頂点sからの最小距離
bool used[MAX_V];//既に使われたかのフラグ
int V;//頂点数

void dijkstra(int s){
    fill(d,d+V,INF);
    fill(used,used+V,false);
    d[s]=0.0;
    while(true){
        int v = -1;
        //まだ使われていない頂点のうち距離が最小のものを探す。
        for(int u=0;u<V;u++){
            if(!used[u] && (v==-1 || d[u]<d[v])){
                v=u;
            }
        }
        if(v==-1) break;
        used[v]=true;
        for(int u=0;u<V;u++){
            d[u] = min(d[u],d[v]+cost[v][u]);
        }
    }
}

double dist(double xi,double yi,double xj,double yj){
    double res = sqrt(1.0*(xi-xj)*(xi-xj)+1.0*(yi-yj)*(yi-yj));
    return res;
}

int main(){
    double xs,ys,xt,yt;
    int a,b,c,e;
    cin>>a>>b>>c>>e;
    xs=1.0*a; ys=1.0*b; xt=1.0*c; yt=1.0*e;
    int N;
    cin>>N;
    V=N+2;
    double x[1010],y[1010],r[1010];
    for(int i=0;i<N;i++){
        int xx,yy,rr;
        cin>>xx>>yy>>rr;
        x[i]=1.0*xx; y[i]=1.0*yy; r[i]=1.0*rr;
    }
    cost[N][N+1]=dist(xs,ys,xt,yt);
    cost[N][N]=0.0;
    cost[N+1][N]=dist(xs,ys,xt,yt);
    cost[N+1][N+1]=0.0;
    for(int i=0;i<N;i++){
        cost[i][N]=max(dist(x[i],y[i],xs,ys)-1.0*r[i], 0.0);
        cost[N][i]=max(dist(x[i],y[i],xs,ys)-1.0*r[i], 0.0);
        cost[i][N+1]=max(dist(x[i],y[i],xt,yt)-1.0*r[i], 0.0);
        cost[N+1][i]=max(dist(x[i],y[i],xt,yt)-1.0*r[i], 0.0);
        for(int j=0;j<N;j++){
            cost[i][j]=max(dist(x[i],y[i],x[j],y[j])-1.0*r[i]-1.0*r[j] , 0.0);
        }
    }
    dijkstra(N);
    cout<<setprecision(20)<<d[N+1]<<endl;
    return 0;
}
