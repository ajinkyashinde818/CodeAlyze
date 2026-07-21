#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <map>
#include <set>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

template<class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}


int N;
vector<ll> a;

int main () {
  cin >> N;

  int ct = 0;
  ll tmp = 0;

  Rep(i, N) {
    ll A;
    cin >> A;
    if (A >= 0) ct++;
    tmp += abs(A);
    a.push_back(abs(A));
  }

  if ((N-ct) % 2 == 0) {
    cout << tmp << "\n";
  } else {
    sort(All(a));
    ll l = a[0];
    cout << tmp - 2 * l << "\n";
  }
}
