#include <array>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  using ll = long long;
  int N, M;
  cin >> N >> M;
  vector<int> T(N);
  for(int i = 0; i < N; ++i)
    cin >> T[i];
  vector<vector<pair<int,int>>> G(N);
  for(int i = 0; i < M; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    --a,--b;
    G[a].emplace_back(c,b);
    G[b].emplace_back(c,a);
  }
  int K;
  cin >> K;
  vector<int> X(K), D(K), P(K);
  for(int i = 0; i < K; ++i){
    cin >> X[i] >> D[i] >> P[i];
    --X[i];
  }
  priority_queue<array<ll,3>,vector<array<ll,3>>,greater<>> pq;
  pq.push({0,0,0});
  const ll INF = 1e18;
  vector<ll> cost(N,INF), day(N,INF), from(N,-1);
  cost[0] = 0;
  day[0] = 0;
  from[0] = 0;
  auto update = [&](int v, ll c, int d, int f){
                  if(cost[v] < c) return false;
                  if(cost[v] > c){
                    cost[v] = c;
                    day[v] = d;
                    from[v] = f;
                    return true;
                  }
                  if(day[v] < d) return false;
                  if(day[v] > d){
                    day[v] = d;
                    from[v] = f;
                    return true;
                  }
                  if(from[v] < 0 or T[from[v]] > T[f]){
                    from[v] = f;
                    return true;
                  }
                  return false;
                };

  while(pq.size()){
    auto p = pq.top();
    pq.pop();
    ll c = p[0], d = p[1], v = p[2];
    if(cost[v] != c or day[v] != d) continue;
    for(auto e : G[v]){
      ll c_ = c + e.first, d_ = d + 1, v_ = e.second;
      if(update(v_,c_,d_,v)){
        pq.push({c_,d_,v_});
      }
    }
  }
  // for(int i = 0; i < N; ++i){
  //   printf("v = %d, cost = %lld, day = %lld, from = %lld\n",i,cost[i],day[i],from[i]);
  // }

  vector<vector<int>> nex(N,vector<int>(25,-1));
  for(int i = 0; i < N; ++i){
    nex[i][0] = from[i];
  }
  for(int i = 1; i < 25; ++i){
    for(int j = 0; j < N; ++j){
      nex[j][i] = nex[nex[j][i-1]][i-1];
    }
  }
  for(int i = 0; i < K; ++i){
    int x = X[i], d = D[i], p = P[i];
    if(day[x] <= d){
      cout << max(0LL,cost[x]-p) << "\n";
      continue;
    }
    ll ans = cost[x];
    int v = x;
    for(int j = 24; j >= 0; --j){
      if(day[nex[v][j]] > d){
        v = nex[v][j];
      }
    }
    if(day[v] > d){
      v = nex[v][0];
    }
    ans -= cost[v];
    ans += max(0LL,cost[v]-p);
    cout << ans << "\n";
  }
}
