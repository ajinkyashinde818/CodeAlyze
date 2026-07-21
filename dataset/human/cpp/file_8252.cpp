/*
 * 2677.cc: Breadth-First Search by Foxpower
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 100000;
const int MAX_E = 17;

/* typedef */

typedef long long ll;

typedef vector<int> vi;
typedef queue<int> qi;

/* global variables */

int prts[MAX_N][MAX_E], ds[MAX_N];
vi clds[MAX_N];

/* subroutines */

int lca(int u, int v) {
  if (ds[u] > ds[v]) swap(u,v);

  for (int i = MAX_E - 1; i >= 0; i--)
    if (((ds[v] - ds[u]) >> i) & 1) v = prts[v][i];
  if (u == v) return u;

  for(int i = MAX_E - 1; i >= 0; i--)
    if (prts[u][i] != prts[v][i]) {
      u = prts[u][i];
      v = prts[v][i];
    }
  
  return prts[u][0];
}

/* main */

int main() {
  int n;
  cin >> n;

  prts[0][0] = -1;
  ds[0] = 0;
  for (int i = 1; i < n; i++) {
    int pi;
    cin >> pi;
    pi--;

    prts[i][0] = pi;
    ds[i] = ds[pi] + 1;
    clds[pi].push_back(i);
  }

  for (int i = 0; i < n; i++)
    for (int e = 0; e < MAX_E - 1; e++)
      prts[i][e + 1] = (prts[i][e] < 0) ? -1 : prts[prts[i][e]][e];

  ll sum = 0;
  int pu = -1;
  qi q;
  q.push(0);

  while (! q.empty()) {
    int u = q.front(); q.pop();
    if (pu >= 0) {
      int cu = lca(pu, u);
      int d = ds[pu] + ds[u] - ds[cu] * 2;
      sum += d;
      //printf("(%d,%d) %d %d\n", pu + 1, u + 1, cu + 1, d);
    }
    pu = u;

    vi &cldu = clds[u];
    for (vi::iterator vit = cldu.begin(); vit != cldu.end(); vit++)
      q.push(*vit);
  }

  printf("%lld\n", sum);
  return 0;
}
