#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

typedef pair<double,int> P;
vector<double> dijkstra(int s, const vector<vector<pair<int,double> > >& G){
    priority_queue< P, vector<P>, greater<P> > que;
    vector<double> d(G.size(), LINF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        int curr  = que.top().second;
        double  dcurr = que.top().first;
        que.pop();
        if(d[curr] < dcurr) continue;
        int i;
        for(i=0; i<(int)G[curr].size(); i++){ 
            int next = G[curr][i].first;
            double  dist = G[curr][i].second;
            if(d[next] > d[curr] + dist){
                d[next] = d[curr] + dist;
                que.push(P(d[next], next));
            }
        }
    }
    return d;
}
 
 
int main(int argc, char* argv[])
{
    int xs,ys,xt,yt;
    scanf("%d%d%d%d", &xs, &ys, &xt, &yt);
    int n;
    scanf("%d", &n);
    vector<vector<int> > z;
    int i;
    for(i=0; i<n; i++) {
        vector<int> v(3);
        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        z.push_back(v);
    }
    {
        vector<int> v(3);
        v[0]=xs; v[1]=ys;
        z.push_back(v);
    }
    {
        vector<int> v(3);
        v[0]=xt; v[1]=yt;
        z.push_back(v);
    }

    vector<vector<pair<int,double> > > G(n+2);
    int j;
    for(i=0; i<n+2; i++) {
        for(j=i+1; j<n+2; j++) {
            double tmp0=z[i][0]-z[j][0];
            double tmp1=z[i][1]-z[j][1];
            double tmp2=z[i][2]+z[j][2];
            double dist=MAX(0, sqrt(tmp0*tmp0+tmp1*tmp1)-tmp2);
            G[i].push_back(make_pair(j, dist));
            G[j].push_back(make_pair(i, dist));
        }
    }
    vector<double> vdist = dijkstra( n, G);
    printf("%.10lf\n", vdist[n+1]);

    return 0;
}
