#include <iostream>
#include <cmath>
#include <queue>
#include <functional>
#include <iomanip>

using P = std::pair<double,double>;

using Node = std::pair<double,int>;

constexpr int MAX_N=1002;

constexpr double INF = 1e9*3;

P s,t;

int n;

double G[MAX_N][MAX_N];

double d[MAX_N];

double dijkstra(int S,int T){

    std::fill(d,d+n,INF);

    std::priority_queue<Node,std::vector<Node>,std::greater<Node>> que;

    que.emplace(d[S]=0.0,S);

    while(!que.empty()) {

        Node node = que.top();

        que.pop();

        if(node.first<d[node.second])
            continue;

        if(node.second==T)
            return d[T];

        for(int i=0;i<n;++i) {

            if(d[i]>d[node.second]+G[node.second][i]){

                d[i]=d[node.second]+G[node.second][i];

                que.emplace(d[i],i);
            }
        }
    }
}

P xy[MAX_N];
double r[MAX_N];

int main() {
    
    std::cin>>s.first>>s.second>>t.first>>t.second;

    std::cin>>n;

    for(int i=1;i<=n;++i)
        std::cin>>xy[i].first>>xy[i].second>>r[i];

    xy[0]=s;

    xy[n+1]=t;

    n+=2;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){

            double len = sqrt(pow(xy[i].first-xy[j].first,2)+pow(xy[i].second-xy[j].second,2))-r[i]-r[j];

            G[i][j]=(len>0)? len : 0;
        }
    }

    double ans=dijkstra(0,n-1);

    std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

    return 0;
}
