#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
const long double M_PI = 3.14159265358979323846265;
const ll INFL = 1LL << 60;//10^18 = 2^60
//ll MOD = 998244353;
void pres(long double A, ll x = 10){cout << fixed << setprecision(x) << A << endl;}


//Union Find
const ll MAX_V = 1000010;

ll par[MAX_V];//
ll Rank[MAX_V];
ll child[MAX_V];

void init_UF(){
  for(ll i = 0; i < MAX_V; i++){
    par[i] = i;
    Rank[i] = 1;
    child[i] = 1;
  }
}

ll find(ll x){
  if(par[x] == x) return x;
  else{
    return par[x] = find(par[x]);
  }
}

bool same(ll x, ll y){
  return find(x) == find(y);
}

void unite(ll x, ll y){
  ll rx = find(x), ry = find(y);
  if(rx != ry){
    if(Rank[rx] >= Rank[ry]){
      par[ry] = rx;
      if(Rank[rx] == Rank[ry]) Rank[rx]++;
      child[rx] += child[ry];
    }else{
      par[rx] = ry;
      child[ry] += child[rx];
    }
  }
}

void compress(vector<ll> &S){
  vector<ll> xs;
  rep(i, S.size()) xs.push_back(S[i]);
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  rep(i, S.size()){
    S[i] = lower_bound(xs.begin(), xs.end(), S[i]) - xs.begin();
  }
}



int main(){
  init_UF();
  ll N;
  cin >> N;
  vector<ll> A(N), B(N);
  ll Axor = 0, Bxor = 0;
  rep(i, N){
    cin >> A[i];
    Axor ^= A[i];
  }
  rep(i, N){
    cin >> B[i];
    Bxor ^= B[i];
  }


  map<ll, ll> b;
  rep(i, N){
    b[B[i]]++;
  }
  b[Bxor]++;
  rep(i, N){
    b[A[i]]--;
  }
  b[Axor]--;
  rep(i, N){
    if(b[B[i]]){
      cout << -1 << endl;
      return 0;
    }
  }


  vector<ll> X, Y;
  rep(i, N){
    if(A[i] != B[i]){
      X.pb(A[i]);
      Y.pb(B[i]);
    }
  }

  //Axor, Bxor, X, Y;
  X.pb(Axor);
  Y.pb(Bxor);
  compress(X);
  compress(Y);
  N = X.size();

  rep(i, N){
    unite(X[i], Y[i]);
  }

  ll con = 0;
  set<ll> used;
  rep(i, N){
    ll x = find(X[i]);
    if(used.count(x)) continue;
    used.insert(x);
    con++;
  }
  cout << N - 1 + con - 1 << endl;

}
