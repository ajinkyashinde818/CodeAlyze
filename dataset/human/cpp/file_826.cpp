#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it<<endl;}cout<<endl;}

vector<ll> divv(ll n);
int main() {
    ll n,r,g,b;

    cin>>r>>g>>b>>n;
    ll mr = (n/r) + 1;
    ll mg = (n/g) + 1;
    ll s =  0;

    rep(i, mr+1) {
        ll u = n;
        u -= i * r;
        if(u<0) continue;
        if(u==0){
            s++;
            continue;
        }
        rep(j, mg+1){
            ll uu = u;
            uu -= j * g;
            if(uu<0) continue;
            if(uu==0){
                s++;
                continue;
            }
            ll aa = uu % b;
            if(aa == 0) s++;
        }

    }
    pr(s);
    
    return 0;
}

vector<ll> divv(ll n) {
  vector<ll> v;
  for(ll i = 1; i*i <= n; i++) {
    if(n%i == 0) {
      v.push_back(i);
      if(i*i != n){
          v.push_back(n/i);
      }
    }
  }
  sort(alll(v));
  return v;
}

class UF { // union find from https://github.com/kartikkukreja/blog-codes (MIT)
    // [usage]
    // auto uf = new UF(n);
    // uf->merge(a, b);
    // ...
public:
    int *id; // inner id
    int cnt; // number of all vartices
    int *sz; // sz[i] means size of i's set
    UF(int N)   {
        cnt = N;
        id = new int[N];
        sz = new int[N];
        for(int i=0; i<N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF() {
        delete [] id;
        delete [] sz;
    }
    int find(int p) {
        int root = p;
        while (root != id[root]) root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    void merge(int x, int y) {
        int i = find(x);
        int j = find(y);
        if (i == j) return;
        
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        cnt--;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    int count() {
        return cnt;
    }
};
