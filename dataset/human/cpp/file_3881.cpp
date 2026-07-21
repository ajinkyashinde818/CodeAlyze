#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pll = pair<ll, ll> ;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=1LL<<60 ;
const ll MOD=1e9+7 ;
const ld PI=acos(-1);
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）

#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに

//最大値、最小値を更新する。aよりbのが大きい（小さい）か等しければaを更新してtrueを返す。そうでなければ何もせずfalseを返す chmax(nowmax,x);
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

// ----- template end ---- //

// ------- library ------- //
void recursive_comb(int *indexes, int s, int rest, function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}
//combinationsおわり


//Dijkstraのベースになる諸々
using Weight = ld; //重み（コスト）の型をここで設定する
const Weight INFW = numeric_limits<Weight>::max();

struct Edge{
    int from, to;
    Weight wei;
    Edge(int from_, int to_, Weight wei_):from(from_),to(to_),wei(wei_){}
};
typedef vector<Edge> Edges;

struct Graph : public vector<Edges>{
    Graph(){ }
    Graph(int V): vector<Edges>(V){ }
    /*
    有向辺を追加する
    */
    void addEdge(int from, int to, Weight wei=1){
        (*this)[from].PB(Edge(from, to, wei));
    }
    /*
    無向辺を追加する
    */
    void addUEdge(int u, int v, Weight wei=1){
      (*this)[u].PB(Edge(u, v, wei));
      (*this)[v].PB(Edge(v, u, wei));
    }
};
 
/*
ダイクストラで使うのはこっち
*/
bool operator>(const Edge &a, const Edge &b){
    return a.wei>b.wei;
}
//戻り値のvector<Weight>にvec.at(ゴールのidx)をすれば合計コストが得られる
//dijkstra(Graph, スタート地点のidx) で呼び出す
vector<Weight> dijkstra(const Graph &G, int src){
    typedef pair<Weight, int> pwi;
    priority_queue<pwi, vector<pwi>, greater<pwi>> pq;
    pq.push(MP(0, src));
    int V = (int)G.size();
    vector<Weight> res(V, -1);
    while(pq.size()){
        auto p = pq.top(); pq.pop();
        Weight d = p.first;
        int v = p.second;
        if(res[v] > -0.5)continue;
        res[v] = d;
        for(const auto &edge : G[v]){
            int to = edge.to;
            Weight wei = edge.wei;
            pq.push(MP(d + wei, to));
        }
    }
    return res;
}

// ----- library end ----- //

//idxの組み合わせの配列（今回は2要素なのでvector<pair>）を入れるための配列
//libraryのforeach_comb()内で使いたいので、main()の外で宣言
vector<pair<int, int> > comb;


int main() {
  ll sx, sy, tx, ty;
  ll N;
  cin >> sx >> sy >> tx >> ty;
  cin >> N;
  
  //方針
  //s, 各バリア, ｇを頂点と考え、sからgへと移動する、重み付き無向グラフにおける最短経路問題＝Dijkstra
  //移動する間に宇宙船を浴びる距離(=時間)をコストとする。
  //バリアが重なっている場合コスト0となるが、Dijkstraはコスト0の辺があっても用いることができる

  vector<tuple<ll, ll, ll> > Barriers;

  //sとgについては、(sx, sy) (tx, ty)を中心とする半径0の円とみなして統一してみる
  //結果としてnode数はN+2個となる
  Barriers.push_back(make_tuple(sx, sy, 0)); //node idx:0
  rep(i, N){
    ll x, y, r;
    cin >> x >> y >> r;
    Barriers.PB(make_tuple(x, y, r));  //node idx:1~N
  }
  Barriers.PB(make_tuple(tx, ty, 0)); //node idx:N+1

  //ここからedge情報を生成する 最大で1002^2なので枝刈りの必要なし

  //まずは組み合わせの配列を作る（今回は2要素なのでvector<pair>）
  //foreach_combは実質main()外の関数なので、combはmain()外で宣言してある
  foreach_comb(N+2, 2, [](int *indexes) {
    comb.PB(MP(indexes[0], indexes[1]));
  });
  
  //edge情報を入れるためのクラスを生成しておく
  Graph graph(N+2); //頂点数はN+2

  for (pair<int, int> eachcmb : comb){
    int fromidx, toidx;
    ll fromx, fromy, fromr, tox, toy, tor;
    ld cost;
    fromidx = eachcmb.first;
    toidx = eachcmb.second;
    tie(fromx, fromy, fromr) = Barriers.at(fromidx);
    tie(tox, toy, tor) = Barriers.at(toidx); 
    cost = max(0.0, pow(pow(abs(fromx-tox),2.0) + pow(abs(fromy-toy),2.0),0.5) - fromr - tor);
    //cout << cost << endl;
    //無向辺を追加していく
    graph.addUEdge(fromidx, toidx, cost);
    //cost, fromidx, toidxをedge情報に入れるが、形式をどうするか
  }

  //idx:0からidx:N+1への最短経路をDijkstraで求める
  cout << fixed << setprecision(10) << dijkstra(graph, 0).at(N+1) << endl;


}
