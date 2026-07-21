#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
struct Node{
    int id;
    T v;
    bool done = false;
    Node(int id, T v=1e15): id(id), v(v) {}
    Node(): id(0), v(1e15) {}
};

template<typename T>
struct Edge{
    int from, to, id;
    T cost;
    Edge(int from, int to, T cost=1, int id=-1): from(from), to(to), cost(cost), id(id) {}
};

template<typename T>
struct Graph{
    int N;
    vector<vector<Edge<T>>> adj;
    vector<Node<T>> node;
    vector<pair<int,int>> i2e; // 辺番号から辺への変換

    Graph(int N): N(N) {
        adj.assign(N, vector<Edge<T>>());
        node.assign(N, Node<T>());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    Graph() {}

    void add_edge(int i, int j, T cost=1, int id=-1){
        Edge<T> e(i, j, cost, id);
        if(id != -1) i2e.emplace_back(i, adj[i].size());
        adj[i].emplace_back(e);
    }

    vector<Edge<T>> get_adj(Node<T> node){
        return adj[node.id];
    }

    void assign(int n){
        N = n;
        adj.assign(N, vector<Edge<T>>());
        node.assign(N, Node<T>());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    void reset(){
        for(int i=0; i<N; ++i){
            node[i].done = false;
            node[i].v = 1e15;
        }
    }
};

struct V {
    double x,y;
    V(double x=0, double y=0): x(x), y(y) {}

    V& operator += (const V& v) { x += v.x; y += v.y; return *this;}
    V operator + (const V& v) const { return V(*this) += v;}
    V& operator -= (const V& v) { x -= v.x; y -= v.y; return *this;}
    V operator - (const V& v) const { return V(*this) -= v;}
    V& operator *= (double s) { x *= s; y *= s; return *this;}
    V operator * (double s) const { return V(*this) *= s;}
    V& operator /= (double s) { x /= s; y /= s; return *this;}
    V operator / (double s) const { return V(*this) /= s;}

    double dot(const V& v) const { return x*v.x + y*v.y;}
    double norm2() const { return x*x + y*y;}
    double norm() const { return sqrt(norm2());}
    V& rotate(double theta) { x = x*cos(theta)-y*sin(theta); y = x*sin(theta)+y*cos(theta); return *this;}
    V rotate90() { return V(-y, x);}
};

struct Circle {
    V o; double r;
    Circle(V o=V(), double r=0): o(o), r(r) {}

    vector<V> get_intersection(const Circle& c){
        V v = c.o - o;
        double d = v.norm();

        if(r + c.r < d + EPS) return {};
        if(d < abs(r - c.r) + EPS) return {};
        if(abs(d - (r + c.r)) < EPS) return vector<V>{v*(r/d) + o};
        if(abs(d - abs(r - c.r)) < EPS) return vector<V>{v*(max(r,c.r)/d) + o};

        double x = (r*r - c.r*c.r + d*d) / (2*d), l = sqrt(r*r - x*x);
        V v1 = v*(x/d), v2 = v1.rotate90()*(l/x);
        return vector<V>{v1+v2+o, v1-v2+o};
    }

    bool isInside(const V& v) {
        return (v-o).norm() < r + EPS;
    }
};

bool operator>(Node<long double> a, Node<long double>  b){
    return a.v > b.v;
}

int main(void){
    long double xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
    int N; cin >> N;
    vector<long double> x(N), y(N), r(N); REP(i,N) cin >> x[i] >> y[i] >> r[i];
    Graph<long double> G(N+2);
    G.add_edge(N, N+1, sqrt((xs-xt)*(xs-xt) + (ys-yt)*(ys-yt)));
    REP(i,N){
        long double d1 = max((long double)0, sqrt((xs-x[i])*(xs-x[i]) + (ys-y[i])*(ys-y[i])) - r[i]);
        long double d2 = max((long double)0, sqrt((xt-x[i])*(xt-x[i]) + (yt-y[i])*(yt-y[i])) - r[i]);
        G.add_edge(N, i, d1);
        G.add_edge(i, N+1, d2);
    }
    REP(i,N-1)FOR(j,i+1,N){
        long double d = max((long double)0, sqrt((x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i])) - r[i] - r[j]);
        G.add_edge(i,j,d);
        G.add_edge(j,i,d);
    }

    priority_queue<Node<long double>,vector<Node<long double>>,greater<Node<long double>>> q;
    q.push(Node<long double>(N,0));
    while(q.size()){
        Node<long double> n = q.top(); q.pop();
        if(G.node[n.id].done) continue;
        G.node[n.id].done = true;
        if(chmin(G.node[n.id].v, n.v)){
            for(Edge<long double> e : G.get_adj(n)) q.push(Node<long double>(e.to, n.v+e.cost));
        }
    }

    long double ans = G.node[N+1].v;
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
