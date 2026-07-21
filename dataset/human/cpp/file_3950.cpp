#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // setprecision
#include <complex> // complex
#include <math.h> 
#include <climits> 
#include <assert.h>
#include <random>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod2 = 1'000'000'007;
constexpr ll mod = 998244353;
const double PI = 3.14159265358;
const int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
const int dy[8] = {0, 1, 0, -1,1,-1,1,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  int N;
  cin >> N;
  N += 2;
  vector<complex<double>> p(N+2);
  p[0] = complex<double>(sx,sy);
  p[N-1] = complex<double>(tx,ty);
  vector<double> r(N);
  r[0] = r[N-1] = 0;
  for(int i=1; i<N-1; i++){
    int x,y,z;
    cin >> x >> y >> z;
    p[i] = complex<double>(x,y);
    r[i] = z;
  } 
  vector<vector<double>> G(N+2, vector<double>(N+2));
  for(int i=0; i<N; i++){
    for(int j=i; j<N; j++){
      G[i][j] = G[j][i] = max(0.0,abs(p[i]-p[j]) - (r[i]+r[j]));
    }
  }
  using pdi = pair<double,int>;
  priority_queue<pdi,vector<pdi>,greater<pdi>> que;
  que.emplace(0,0);
  vector<double> dist(N,INF);
  dist[0] = 0;
  while(que.size()){
    double cost;
    int v;
    tie(cost,v) = que.top();
    que.pop();
    if(cost > dist[v]) continue;
    for(int nv=0; nv<N; nv++){
      double ncost = cost + G[v][nv];
      if(ncost < dist[nv]){
        dist[nv] = ncost;
        que.emplace(ncost,nv);
      }
    }
  }
  cout << fixed << setprecision(10) << dist[N-1] << "\n";
  return 0;
}
