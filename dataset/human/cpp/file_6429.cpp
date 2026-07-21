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
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct mint {
    long long x;
public:
    mint(long long x=0) : x((x%mod+mod)%mod) {}
    mint operator-() const { 
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    bool operator <(const mint& r){return this->x<r.x;}
    bool operator ==(const mint& r){return this->x==r.x;}
    bool operator !=(const mint& r){return this->x!=r.x;}
    void operator++() {
        x++;
    }
    void operator--() {
        x--;
        if(x<0) x += mod;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};

int main(){
  mint N;
  cin>>N.x;
  string S;
  cin>>S;
  vector<int> v(N.x*2);
  rep(i,N.x*2){
    if(S[i] == 'B') v[i] = 0;
    else v[i] = 1;
  }
  mint ans = 0;
  if(v[0] == 0&& v[N.x*2-1] == 0){
    vector<int> t(N.x * 2);
    t[0] == 0;
    rep(i,N.x*2-1){
      if(v[i+1]!=v[i]) t[i+1] = t[i];
      else t[i+1] = 1-t[i];
    }
    ll check = 0;
    rep(i,N.x*2) check += t[i];
    if(check == N.x){
      if(t[N.x*2-1]==1) {
        mint cnt = 0;
        ans = 1;
        rep(i,N.x * 2){
          cnt += t[N.x*2-1-i];
          if(t[N.x*2-1-i]==0) {
            ans*=cnt;
            --cnt;
          }
        }
        rep(i,N.x) ans *= (mint)(i+1);
      }
    }
  }
  cout<<ans<<endl;
}
