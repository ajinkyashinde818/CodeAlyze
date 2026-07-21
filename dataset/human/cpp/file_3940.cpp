#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, long long> pdl;

#define rep(i, n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007

vector<pair<double, ll> > g[1099]; ll N;

double eucliddist(ll x, ll y, ll u, ll v) {

    double ans = sqrt((x-u)*(x-u) + (y-v)*(y-v));
    return ans;
}

vector<double> dist(1099, 1e18+5);
vector<bool> visited(1099, false);
void dijkstra(int s) {

    /*
    priority_queue< pdl, vector<pdl>, greater<pdl> > pq;
    pq.push(mp(0, s));

    while(!pq.empty()) {

        pdl v = pq.top(); pq.pop();
        visited[v.second] = true;
        dist[v.second] = min(dist[v.second], v.first);
        //cout<<v.first<<" "<<v.second<<endl;

        for(int i = 0 ;i < g[v.second].size(); i++) {
            pdl u = g[v.second][i];

            if(not visited[u.second]  and  dist[v.second] + u.first < dist[u.second]) {
                dist[u.second] = dist[v.second] + u.first;
                pq.push(mp(dist[u.second], u.second));
            }
        }
    }*/

    dist[s]=0;
    while(true) {
        visited[s] = true;

        for(int i=0;i<g[s].size();i++) {
            if(not visited[g[s][i].second]) {
                dist[g[s][i].second] = min(dist[g[s][i].second], dist[s] + g[s][i].first);
            }
        }

        double minm = LONG_LONG_MAX; ll index = -1;

        for(int i=1;i<=N;i++) {
            if(dist[i] < minm and (not visited[i])) {
                minm = dist[i];
                index = i;
            }
        }

        if(index == -1) break;
        s = index;
    }
}

int main() {
    map<pair<ll, ll>, pair<ll, ll> > temp;
    ll x1,y1,x2,y2,x,y,r;
    cin>>x1>>y1>>x2>>y2;

    int n;
    cin>>n;

    temp[mp(x1,y1)] = mp(0, 1);
    temp[mp(x2,y2)] = mp(0, 2);
    int node = 3;
    for(int i = 0;i < n;i++) {
        cin>>x>>y>>r;
        if(temp.find(mp(x,y)) == temp.end()) {
            temp[mp(x,y)] = mp(r, node++);
        } else {
            if(r > temp[mp(x,y)].first) {
                temp[mp(x,y)].first = r;
            }
        }
    }

    for(auto i = temp.begin();i != temp.end();i++) {

        x = (i->first).first;
        y = (i->first).second;
        r = (i->second).first;
        ll na = (i->second).second;

        auto j = i;
        j++;

        for(;j != temp.end();j++) {
            ll u = (j->first).first;
            ll v = (j->first).second;
            ll r2 = (j->second).first;
            ll na2 = (j->second).second;

            double dist = eucliddist(x, y, u, v);
            double ans = 0;
            if(dist-r-r2 > 0) { // doubt
                ans = dist-r-r2;
            }

            g[na].pb(mp(ans, na2));
            g[na2].pb(mp(ans, na));
        }
    }
    N = temp.size();

    // shortest distance between node 1 and 2

    //for(int i=1;i<=3;i++) {
      //  cout<<i<<" ";
        //for(int j=0; j < g[i].size();j++) cout<<g[i][j].first<<","<<g[i][j].second<<" "; cout<<endl;
    //}

    dijkstra(1);

    printf("%.12f", dist[2]);


    return 0;
}
