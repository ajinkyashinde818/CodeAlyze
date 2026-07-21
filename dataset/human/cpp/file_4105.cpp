#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll, int> plli;
typedef pair<int, pii> pipii;
typedef vector<vector<int> > mati;
typedef vector<vector<double> > matd;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<pll> vpll;

#define FOR(i,x,y) for(ll i=(ll)x; i<(ll)y; ++i)
#define REP(i,y) FOR(i, 0, y)
#define RFOR(i,x,y) for(ll i=(ll)x; i>=(ll)y; --i)
#define RREP(i,x) RFOR(i, x, 0)
#define ALL(a) a.begin(), a.end()
#define pb push_back

inline void IN(void){
  return;
}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){
  cin >> first;
  IN(rest...);
  return;
}

inline void OUT(void){
  cout << "\n";
  return;
}

template <typename First, typename... Rest>
void OUT(First first, Rest... rest){
  cout << first << " ";
  OUT(rest...);
  return;
}

template <typename T>
void vec_print(vector<T> VEC){
  REP(i, VEC.size()){
    cout << VEC[i] << " ";
  }
  cout << "\n";
};

template <typename T>
void mat_print(vector<vector<T> > MAT){
  REP(i, MAT.size()){
    REP(j, MAT[i].size()){
      cout << MAT[i][j] << " ";
    }
    cout << "\n";
  }
};

template <typename CLASS1, typename CLASS2>
class HOGE{
  public:
    CLASS1 key;
    CLASS2 value;
    HOGE(void){
      return;
    };
    HOGE(CLASS1 key, CLASS2 value){
      this->key = key;
      this->value = value;
    };
    ~HOGE(void){
      return;
    };

    void print(void){
      cout << "key : " << key << ", value : " << value << "\n";
      return;
    };
    
    bool operator==(const HOGE &obj){
      return (this->value == obj.value);
    };
    bool operator<(const HOGE &obj){
      return (this->value < obj.value);
    };
    bool operator>(const HOGE &obj){
      return (this->value > obj.value);
    };
};

template <typename CLASS1, typename CLASS2>
bool operator==(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){
  return hoge1.value == hoge2.value;
};

template <typename CLASS1, typename CLASS2>
bool operator<(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){
  return hoge1.value < hoge2.value;
};

template <typename CLASS1, typename CLASS2>
bool operator>(const HOGE<CLASS1, CLASS2> &hoge1, const HOGE<CLASS1, CLASS2> &hoge2){
  return hoge1.value > hoge2.value;
};

constexpr int INF = (1<<30);
constexpr ll INFLL = 1LL<<62;
constexpr long double EPS = 1e-12;
constexpr ll MOD = (ll)((1E+9)+7);

class Dijkstra{
  //Dijkstra algorithm
  //calculation time complexity: O(|W| log |V|)
  //useful without negative cost
  private:
    struct edge { ll to; double cost; };
    typedef pair<ll, ll> P; //first is the shortest distance, second is the number of vertex

    ll V, E;
    vector<double> d;
    vector<ll> prev;
    vector<vector<edge> > G;

  public:
    Dijkstra(ll V, vector<ll> From, vector<ll> To, vector<double> Cost){
      //num of vertex
      this->V = V;
      d.resize(V, INFLL);
      prev.resize(V, -1);
      E = (ll)From.size();
      if(To.size() != E || Cost.size() != E){
        fprintf(stderr, "Sizes are different, %ld %ld %ld\n", From.size(), To.size(), Cost.size());
        exit(0);
      }
      G.resize(V);
      for(ll i=0; i<E; ++i){
        edge tmp_forward = {To[i], Cost[i]};
        G[From[i]].push_back(tmp_forward);
      }
      return;
    };

    ~Dijkstra(void){
      return;
    };

    //calculate shortest path from s vertex to others
    void shortest_path(ll s){
      priority_queue<P, vector<P>, greater<P> > que;
      for(ll i=0; i<V; ++i) d[i] = INFLL;
      d[s] = 0;
      que.push(P(0, s));

      while(!que.empty()){
        P p = que.top(); que.pop();
        ll v = p.second;
        if(d[v] < p.first) continue;
        for(ll i=0; i<G[v].size(); i++){
          edge e = G[v][i];
          if(d[e.to] > d[v] + e.cost){
            d[e.to] = d[v] + e.cost;
            prev[e.to] = v;
            que.push(P(d[e.to], e.to));
          }
        }
      }
      return;
    };

    double get_distance(ll vertex){
      return d[vertex];
    };

    //shortest path to vertex t
    vector<ll> get_path(ll t){
      vector<ll> path;
      for(; t!=-1; t=prev[t]){
        path.push_back(t);
      }
      reverse(path.begin(), path.end());
      return path;
    };
};

double dist(vll x1, vll x2){
  ll dx = x1[0]-x2[0];
  ll dy = x1[1]-x2[1];
  return sqrt(dx*dx+dy*dy);
}

int main(){
  cin.tie(0); // cut the cin and cout (default, std::flush is performed after std::cin)
  ios::sync_with_stdio(false); // cut the iostream and stdio (DON'T endl; BUT "\n";)

  ll xs, ys, xt, yt;
  IN(xs,ys,xt,yt);
  ll N;
  IN(N);
  vvll verteces(N+2, vll(3));
  verteces[0][0] = xs; verteces[0][1] = ys; verteces[0][2] = 0;
  verteces[N+1][0] = xt; verteces[N+1][1] = yt; verteces[N+1][2] = 0;
  FOR(i,1,N+1){
    ll x, y, r;
    IN(x,y,r);
    verteces[i][0]=x; verteces[i][1]=y; verteces[i][2]=r;
  }

  vll From, To;
  vector<double> Cost;
  REP(i, N+2){
    FOR(j, i+1, N+2){
      double l = dist(verteces[i], verteces[j]);
      From.push_back(i);
      To.push_back(j);
      Cost.push_back(max(l-(double)verteces[i][2]-(double)verteces[j][2], 0.0));
      From.push_back(j);
      To.push_back(i);
      Cost.push_back(max(l-(double)verteces[i][2]-(double)verteces[j][2], 0.0));
    }
  }

  Dijkstra D(N+2, From, To, Cost);

  D.shortest_path(0);

  printf("%.12lf\n", D.get_distance(N+1));

  return 0;
}
