#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<D,int> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
vector<P>g[1005];
int n;
D xs,ys,xt,yt;
D x[1005],y[1005],r[1005],d[1005];
int main(void){
    cin>>xs>>ys>>xt>>yt>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>r[i];
        g[0].PB(P(max(D(0),sqrt((xs-x[i])*(xs-x[i])+(ys-y[i])*(ys-y[i]))-r[i]),i));
        g[i].PB(P(max(D(0),sqrt((xt-x[i])*(xt-x[i])+(yt-y[i])*(yt-y[i]))-r[i]),n+1));
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            g[i].PB(P(max(D(0),sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]))-r[i]-r[j]),j));
            g[j].PB(P(max(D(0),sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]))-r[i]-r[j]),i));
        }
    }
    for(int i=1;i<=n+1;i++)d[i]=10000000000;
    priority_queue<P,vector<P>,greater<P> >dik;
    dik.push(P(0,0));
    while(!dik.empty()){
        int v=dik.top().S;
        D c=dik.top().F;
        dik.pop();
        if(c>d[v])continue;
        for(int i=0;i<g[v].size();i++){
            int u=g[v][i].S;
            D l=g[v][i].F;
            if(d[u]>c+l){
                d[u]=c+l;
                dik.push(P(c+l,u));
            }
        }
    }
    printf("%.10lf\n",min(d[n+1],sqrt((xs-xt)*(xs-xt)+(ys-yt)*(ys-yt))));
}
