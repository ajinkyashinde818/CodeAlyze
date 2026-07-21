#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<62;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T>struct dijkstra{//T=int or ll
  struct Node{
    vector<T> edges_to;
    vector<T> edges_cost;
    bool done;
    T cost=-1;
  };
  vector<Node> graph;
  void init(int N){
    graph.resize(N);
  }
  void add(int from, int to, T cost){
    graph[from].edges_to.push_back(to);
    graph[from].edges_cost.push_back(cost);
  }
  void shortest(T start){
    priority_queue<pair<T,T>,vector<pair<T,T>>,greater<pair<T,T>>> d;
    d.push(make_pair(0,start));
    while(!d.empty()){
      pair<T,T> p = d.top();
      d.pop();
      Node &point = graph[p.second];
      if(point.done) continue;
      point.done = true;
      point.cost = p.first;
      for(T i = 0; i < (T)point.edges_to.size(); i++){
        if(graph[point.edges_to[i]].done)continue;
        d.push(make_pair(point.cost+point.edges_cost[i],point.edges_to[i]));
      }
    }
  }
};

int main() {
  P s,t;
  cin>>s.first>>s.second>>t.first>>t.second;
  ll N;
  cin>>N;
  vector<vector<lb>> v(N,(vector<lb>(3)));
  rep(i,N){
    rep(j,3) cin>>v[i][j];
  }
  vector<vector<lb>> g(N+2,vector<lb>(N+2,INF));
  rep(i,N){
    rep(j,N){
      if(i==j) g[i][j] = 0;
      else {
        lb X = v[i][0]-v[j][0],Y = v[i][1]-v[j][1];
        g[i][j] = max((lb)sqrt(X*X+Y*Y)-v[i][2]-v[j][2],(lb)0);
      }
    }
  }
  rep(i,N+2){
    if(i<N){
      lb X = s.first - v[i][0],Y = s.second - v[i][1];
      g[N][i] = g[i][N] = max((lb)sqrt(X*X+Y*Y)-v[i][2],(lb)0);
    }
    else if(i==N) g[N][i]=g[i][N]=0;
    else if(i==N+1) {
      lb X = s.first-t.first,Y = s.second-t.second;
      g[N][i] = g[i][N] = (lb)sqrt(X*X+Y*Y);
    }
  }
  rep(i,N+2){
    if(i<N){
      lb X = t.first - v[i][0],Y = t.second - v[i][1];
      g[N+1][i] = g[i][N+1] = max((lb)sqrt(X*X+Y*Y)-v[i][2],(lb)0);
    }
    else if(i==N+1) g[N+1][i]=g[i][N+1]=0;
  }
  dijkstra<lb> D;
  D.init(N+2);
  rep(i,N+2){
    rep(j,N+2){
      D.add(i,j,g[i][j]);
    }
  }
  D.shortest(N);
  cout<<fixed<<setprecision(10);
  cout<<D.graph[N+1].cost<<endl;
}
