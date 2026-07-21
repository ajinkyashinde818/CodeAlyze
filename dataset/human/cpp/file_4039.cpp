typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

ll x_s,y_s,x_t,y_t;
ll n;
struct point {
    ll x,y,r;
};

point p[1010];

struct edge {
    ll to;
    double cost;
};

unordered_map <ll,vector<edge> > edges;

int main(){
    std::cin >> x_s>>y_s>>x_t>>y_t;
    std::cin >> n;
    
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i].x>>p[i].y>>p[i].r;
    }
    // 視点と終点も
    p[0].x = x_s;
    p[0].y = y_s;
    p[n+1].x = x_t;
    p[n+1].y = y_t;
    
    for (int i = 0; i <= n+1; i++) {
        for (int j = i+1; j <= n+1; j++) {
            if(i==j) continue;
            double cost = max(sqrt(pow((p[i].x - p[j].x),2)+pow((p[i].y - p[j].y),2)) - (p[i].r + p[j].r), (double)0);
            edges[i].push_back({j,cost});
            edges[j].push_back({i,cost});
            // std::cout << i<<" " <<j<<" "<<cost << std::endl;
        }
    }
    
    priority_queue<pair<double,ll>, vector<pair<double,ll>>, greater<pair<double,ll>> > que;
    double d[1010];
    const ll INF = 1e11;
    for (int i = 0; i <= n+1; i++) {
        d[i]=INF;
    }
    d[0]=0;
    
    que.push({0,0});
    
    while(!que.empty()){
        double cost = que.top().first;
        ll node = que.top().second;
        que.pop();
        
        if(d[node] < cost) continue;
        
        for (auto e : edges[node]) {
            if(d[e.to] > cost + e.cost){
                d[e.to] = cost + e.cost;
                que.push({d[e.to],e.to});
            }
        }
    }
    
    std::cout <<setprecision(13) <<d[n+1] << std::endl;
}
