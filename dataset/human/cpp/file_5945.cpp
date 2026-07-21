#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N,C;
  cin>>N>>C;
  vector<vector<ll>> v(N,vector<ll>(2));
  for(ll i = 0LL; i < N; i++) cin>>v[i][0]>>v[i][1];
  ll ans = 0LL;
  ll cnt = 0LL;
  ll cal = 0LL;
  vector<vector<ll>>  turna,turnb;
  for(ll i = 0LL; i < N; i++){
    cnt = v[i][0];
    cal+=v[i][1];
    if(chmax(ans,cal-cnt))turna.push_back({i,ans});
  }
  ans=0LL;
  reverse(v.begin(),v.end());
  cnt = 0LL;
  cal = 0LL;
  for(ll i = 0LL; i < N; i++){
    cnt = C-v[i][0];
    cal+=v[i][1];
    if(chmax(ans,cal-cnt)) turnb.push_back({i,ans});
  }
  ll ansa = 0LL;
  cnt = 0LL;
  cal=0LL;
  reverse(v.begin(),v.end());
  for(ll i = N-1; i > 0; i--){
    cal+=v[i][1];
    cnt=2LL*(C-v[i][0]);
    vector<ll> s = {i,0};
    auto ite = lower_bound(turna.begin(),turna.end(),s);
    if(ite==turna.begin()) continue;
    chmax(ansa,cal-cnt+(*(ite-1))[1]);
  }
  ll ansb = 0LL;
  cnt = 0LL;
  cal=0LL;
  reverse(v.begin(),v.end());
  for(ll i = N-1; i>0; i--){
    cal+=v[i][1];
    cnt=2LL*v[i][0];
    vector<ll> s = {i,0};
    auto ite = lower_bound(turnb.begin(),turnb.end(),s);
    if(ite==turnb.begin()) continue;
    chmax(ansb,cal-cnt+(*(ite-1))[1]);
  }
  if(turna.empty()) turna.push_back({0,0});
  if(turnb.empty()) turnb.push_back({0,0});
  cout<<max(max((*(turna.end()-1))[1],(*(turnb.end()-1))[1]),max(ansa,ansb))<<endl;
}
