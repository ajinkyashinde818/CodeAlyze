#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;

struct bar{
    double x,y,r;
    bar(){};
    bar(double x, double y, double r) : x(x), y(y), r(r){};
};

const int MAX = 1001;
const int WHITE = 1;
const int BLACK = 2;
const int GRAY = 3;
const double INFTY = numeric_limits<double>::max();
vector<pair<int,double> > G[MAX];
int V, gv;

double bfs(int s){
    vector<double> d(V,INFTY);
    vector<int> color(V, WHITE);
    d[s] = 0.0;
    color[s] = GRAY;
    priority_queue<pair<double, int>, vector<pair<double,int> >, greater<pair<double,int> > > Q;
    Q.push(make_pair(d[s],s));

    while(!Q.empty()){
        auto q = Q.top(); Q.pop();
        double c = q.first;
        int u = q.second;
        if(d[u] < c) continue;
        color[u] = BLACK;
        for(auto v : G[u]){
            if(color[v.first] == BLACK) continue;
            if(d[v.first] > d[u] + v.second){
                d[v.first] = d[u] + v.second;
                Q.push(make_pair(d[v.first], v.first));
            }
        }
    }
    return d[gv];
}

double calc(bar &A, bar &B){
    return max(sqrt( (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y) ) - A.r - B.r, 0.0);
}

int main(){
    double x,y,r;
    bar s,g;
    cin >> x >> y; s = bar(x,y,0.0);
    cin >> x >> y; g = bar(x,y,0.0);
    int N; cin >> N;
    vector<bar> bs(N+2);
    bs[0] = s; bs[N+1] = g;
    gv = N+1;
    V = N+2;
    for(int i=1;i<=N;i++){
        cin >> x >> y >> r;
        bs[i] = bar(x,y,r);
    }

    for(int i=0;i<N+2;i++){
        for(int j=0;j<N+2;j++){
            if(i==j) continue;
            double cost = calc(bs[i], bs[j]);
            G[i].push_back(make_pair(j,cost));
            G[j].push_back(make_pair(i,cost));
        }
    }
    cout << fixed << setprecision(15);
    cout << bfs(0) << endl;
    return 0;
}
