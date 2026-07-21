#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <array>
#include <bitset>

long long mod = 1e9+7;
class Mint {
public:
  long long x;
  Mint(){}; // 引数なしでも定義できるように引数なしコンストラクタも用意しておく
  Mint(long long a){
    x = a%mod;
    while(x<0){
      x += mod;
    }
  };
  Mint& operator += (const Mint &a){
    x+=a.x;
    x%=mod;
    return *this;
  }
  Mint& operator -= (const Mint &a){
    x += (mod - a.x);
    x%=mod;
    return *this;
  }
  Mint& operator *= (const Mint &a){
    x*=a.x;
    x%=mod;
    return *this;
  }

  // a^n mod を計算する
  // Useaeg: Mint z = Mint(2).pow(n);
  Mint pow(long long n) const {
    if (n==0) return Mint(1);
    Mint y = pow(n>>1); // pow(n/2)を計算する
    y *= y;
    if (n%2==1) y *= *this;
    return y;
  }

  // a^{-1} mod を計算する
  Mint modinv(const Mint &a) const {
    return a.pow(mod-2);
  }

  Mint& operator /= (const Mint &a) {
    x *= modinv(a).x;
    x %= mod;
    return *this;
  }

  Mint operator + (Mint &a) const {
    Mint y(*this);
    y += a;
    return y;
  }

  Mint operator - (Mint &a) const {
    Mint y(*this);
    y -= a;
    return y;
  }

  Mint operator * (Mint &a) const {
    Mint y(*this);
    y *= a;
    return y;
  }

  Mint operator / (Mint &a) const {
    Mint y(*this);
    y/=a;
    return y.x;
  }

  // nCk @mod を計算する
  Mint nCk(Mint &n, const long long k) const {
    Mint y = Mint(1);
    Mint iy = Mint(1);
    Mint one = Mint(1);
    // 割り算の演算は時間がかかるので最後に1度だけ行うようにすること
    for (Mint i(0); (i.x)<k; i.x++){
      y *= (n-i);
      iy *= (i + one);
    }
    return y / iy;
  }

  // nPk @mod を計算する
  Mint nPk(Mint &n, long long k) const {
    Mint y(1);
    for (Mint i(0); (i.x)<k; i.x++){
      y *= (n-i);
    }
    return y;
  }
};

class UnionFind {
private:
  int n;
  std::vector<int > parent;
public:
  UnionFind(int num) :
    n(num) {
      parent = std::vector<int> (n);
      for (int i=0; i<n; i++) {
        parent[i] = i;
      }
    }
  int GetRoot(int i) {
    int n = i;
    while(parent[n]!=n) {
      n = parent[n];
    }
    parent[i] = n;
    return n;
  }

  bool SameGroup(int n, int m) {
    n = this->GetRoot(n);
    m = this->GetRoot(m);
    return n==m;
  }

  bool Unite(int n, int m) {
    n = this->GetRoot(n);
    m = this->GetRoot(m);
    if (n==m) return false;
    parent[n] = m;
    return true;
  }
};

int getgcd(int a, int b) {
  int max = std::max(a, b);
  int min = std::min(a, b);
  if (min==0) return max;
  return getgcd(min, max%min);
}

Mint mynCk(int n, int k) {
  if (2*k>n) return mynCk(n, n-k);
  Mint retval(1);
  Mint iretval(1);
  for (int i=0; i<k; i++) {
    retval *= Mint(n-i);
  }
  for (int i=1; i<=k; i++) {
    iretval *= Mint(i);
  }
  return retval / iretval;
}

int main() {
  long long xs, ys, xg, yg;
  std::cin >> xs >> ys >> xg >> yg;
  int N;
  std::cin >> N;
  std::vector<long long> x(N+2), y(N+2), r(N+2);
  x[0] = xs;
  y[0] = ys;
  r[0] = 0;
  for (int i=1; i<=N; i++) {
    std::cin >> x[i] >> y[i] >> r[i];
  }
  x[N+1] = xg;
  y[N+1] = yg;
  r[N+1] = 0;
  std::vector<std::pair<int, double> > edges[N+4];
  for (int i=0; i<=N+1; i++) {
    for (int j=i+1; j<=N+1; j++) {
      double d = sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2)) - r[i] - r[j];
      d = std::max(d, 0.0);
      edges[i].push_back(std::make_pair(j, d));
      edges[j].push_back(std::make_pair(i, d));
      // printf("dist(%d, %d)=%lf\n", i, j, d);
    }
  }
  std::priority_queue<std::pair<double, int>,
                      std::vector<std::pair<double, int> >,
                      std::greater<std::pair<double, int> > > queue;
  std::vector<double> dist(N+4, 1e18);
  queue.push(std::make_pair(0.0, 0));
  dist[0] = 0.0;
  while(queue.size()>0) {
    double d = queue.top().first;
    int v = queue.top().second;
    queue.pop();
    if (dist[v]<d) continue;
    for (auto &entry : edges[v]) {
      int vv = entry.first;
      double dd = entry.second;
      if (dist[vv] > dist[v] + dd) {
        dist[vv] = dist[v] + dd;
        // printf("dist[%d]=%lf\n", vv, dist[vv]);
        queue.push(std::make_pair(dist[vv], vv));
      }
    }
  }
  printf("%.12lf\n", dist[N+1]);
  return 0;
}
