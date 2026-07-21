// https://atcoder.jp/contests/abc118/tasks/abc118_c

// http://ctylim.hatenablog.com/entry/2015/08/30/191553
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
// #include <queue>
#include<ext/pb_ds/priority_queue.hpp>
#include <stack>
#include <cstdlib>
#include <cstdio>

#define ALL(a) (a).begin(), (a).end()
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
#define RSORT(c) sort((c).rbegin(), (c).rend())
#define MAXINDEX(c) distance((c).begin(), max_element((c).begin(), (c).end()))
#define MININDEX(c) distance((c).begin(), min_element((c).begin(), (c).end()))
#define DEBUG(x) std::cerr << #x << " = " << (x) << " (" << __FILE__ << "::" << __LINE__ << ")" << std::endl;
#define ERROR(s) std::cerr << "Error::" << __FILE__ << "::" << __LINE__ << "::" << __FUNCTION__ << "::" << (s) << std::endl;
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)

#define repd(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;

template <typename T>
T inputValue(){
  T a;
  std::cin >> a;
  // scanf("%llu", &a);
  return a;
}

void inputArray(int *p, int a){
  rep(i, a){
    std::cin >> p[i];
    // scanf("%d",p+i);
  }
}

template <typename T>
void inputVector(std::vector<T> *p, int a){
  rep(i, a){
    T input;
    std::cin >> input;
    // scanf("%llu", &input);
    p->push_back(input);
  }
}

template <typename T>
void output(T a, int precision){
  if (precision > 0){
    std::cout << std::setprecision(precision) << a << "\n";
  }else{
    std::cout << a << "\n";
  }
}

void print() { std::cout << std::endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail){
  std::cout << head << ",";
  print(std::forward<Tail>(tail)...);
}

using namespace std;

typedef double WT;

struct Edge{
  int64_t from;
  int64_t to;
  WT w;
};

struct DNode {
  WT cost;
  int64_t prev;
};

// const WT INF = DBL_MAX;
WT INF = std::numeric_limits<WT>::max();

std::vector<DNode> dijkstra(
  std::vector<std::vector<Edge>> &adj, 
  const int64_t nodeCount, 
  const int64_t start)
{
  typedef std::pair<WT, int64_t> P; // first: weight, second: node_index

  std::vector<DNode> dinfo(nodeCount, DNode{INF, -1});
  std::priority_queue<P, vector<P>, greater<P>> q;

  dinfo[start] = DNode{0, -1};
  q.push(P(0, start));

  while(q.size() != 0) {

    P n = q.top();
    q.pop();
    WT fCost = n.first;
    int64_t fNode = n.second;

    if(dinfo[fNode].cost< fCost) {
      continue;
    }
    //     cost_S2F     cost_F2N
    // [S] --....-->[F]---------|
    //  |----....--------[N]<---|
    //      cost_S2N

    WT cost_S2F = dinfo[fNode].cost;
    for (auto i = (adj[fNode]).begin(); i != (adj[fNode]).end(); ++i){
      int64_t nNode = (*i).to;
      WT cost_F2N = (*i).w;
      WT cost_S2N = dinfo[nNode].cost;

      if(cost_S2F + cost_F2N < cost_S2N){
        dinfo[nNode].cost = cost_S2F + cost_F2N;
        q.push(P(dinfo[nNode].cost, nNode));
        dinfo[nNode].prev = fNode;
      }
    }

  }
  return dinfo;
}



int main(int argc, char **argv)
{
  int64_t xs, ys, xt, yt, N;
  cin >> xs >> ys >> xt >> yt >> N;
  vector <int64_t> x(N+2),y(N+2),r(N+2);

  x[0]=xs;y[0]=ys;r[0]=0;
  x[1]=xt;y[1]=yt;r[1]=0;
  for(int i=2;i<N+2;i++){
    cin >> x[i] >> y[i] >> r[i];
    // print(x[i], y[i], r[i]);
  }

  vector<vector<Edge>> graph(N+2);

  for(int i=0;i<N+2;i++){
    for(int j=0;j<i;j++){
      double d = sqrt(double((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
      d = d - double(r[i] + r[j]);
      d = d > 0.0 ? d : 0.0; 
      graph[i].push_back(Edge{i, j, d});
      graph[j].push_back(Edge{j, i, d});
      // print(i,j,d,INF);
    }
  }

  auto dis = dijkstra(graph, N+2, 0);
  // EACH(i,dis){
  //   print((*i).cost, (*i).prev);
  // }
  output(dis[1].cost, 12);
  return 0;
  }
