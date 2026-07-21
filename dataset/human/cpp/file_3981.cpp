#include <numeric>
#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
using namespace std;
#define int long long
#define ll long long
#define inf  1000000007
#define rep(i,j,n) for(int i=j;i<n;i++)
double pi = 3.141592653589793;
//使うやつはここから下に置こうな
struct edge{int to;double cost;};
typedef pair<int,double>P;
vector<edge> G[100005];
double d[100005];
int n;
 
void dijkstra(long long k){
    priority_queue<P,vector<P>,greater<P> >que;
    fill(d,d+n,1e17);
    d[k]=0;
    que.push(P(0,k));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size(); i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
 
signed main()
{
    int sx,sy,gx,gy;cin>>sx>>sy>>gx>>gy;
    cin>>n;
    int a[1145],b[1145],c[1141];
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    a[n]=sx;b[n]=sy;c[n]=0;
    a[n+1]=gx;b[n+1]=gy;c[n+1]=0;
    n+=2;
    rep(i,0,n){
        rep(j,0,n){
            if(i==j)continue;
            double h=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]))-c[i]-c[j];
            if(h<0)h=0;
            G[i].push_back(edge{j,h});
        }
    }
    dijkstra(n-2);
    cout<<setprecision(15)<<d[n-1]<<endl;
    return 0;
}
