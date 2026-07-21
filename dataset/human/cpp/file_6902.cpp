#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <utility>
#include <set>
using namespace std;
using ll = int64_t;
using pll = pair<ll,ll>;

// possible iff for each X, BC[X] <= n-AC[x] i.e. the number of Bs we have to place is <= the number of spots
// where it is legal to place a B i.e. AC[X]+BC[X] <= n
// At each position put the X with the highest AC[X]+BC[X] as long as BC[X]>0?

struct Data {
  Data(vector<ll> COUNT, vector<ll> BC_) {
    BC = vector<ll>(BC_.begin(), BC_.end());
    C = vector<ll>(COUNT.begin(), COUNT.end());
    for(ll i=0; i<C.size(); i++) {
      if(C[i] > 0 && BC[i] > 0) {
        V.insert({C[i], i});
      }
    }
  }
  void subtractA(ll x) {
    V.erase({C[x], x});
    C[x]--;
    if(C[x] > 0) {
      V.insert({C[x], x});
    }
  }
  void subtractB(ll x) {
    BC[x]--;
    if(BC[x] == 0) {
      V.erase({C[x], x});
      C[x] = 0;
    } else {
      subtractA(x);
    }
  }
  ll max(ll neq) {
    /*for(auto [x,y] : V) {
      cerr << x << " " << y << endl;
    }*/
    auto it = V.begin();
    if(it->second != neq) {
      return it->second;
    } else {
      it++;
      assert(it->second != neq);
      return it->second;
    }
  }
  vector<ll> BC;
  vector<ll> C;
  multiset<pll,greater<pll>> V;
};

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n, 0);
  vector<ll> B(n, 0);
  vector<ll> C(n+1, 0);
  vector<ll> BC(n+1, 0);
  for(ll i=0; i<n; i++) {
    cin >> A[i];
    C[A[i]]++;
  }
  for(ll i=0; i<n; i++) {
    cin >> B[i];
    C[B[i]]++;
    BC[B[i]]++;
  }
  for(ll i=0; i<=n; i++) {
    if(C[i]>n) {
      cout << "No" << endl;
      return 0;
    }
  }

  Data d(C, BC);

  vector<ll> ANS(n, 0);
  for(ll i=0; i<n; i++) {
    d.subtractA(A[i]);
    ll x = d.max(A[i]);
    ANS[i] = x;
    d.subtractB(x);
  }
  cout << "Yes" << endl;
  for(ll i=0; i<n; i++) {
    cout << ANS[i];
    if(i+1 < n) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}
