#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<double> vf;
typedef vector<vf> vvf;

double pow(double a, ll i) {
  double ret = 1;
  for (ll j = 0; j < i; j++) ret *= a;
  return ret;
}

double dist(pii a, pii b) {
  double x = pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
  return sqrt(x);
}

int main() {
  pii s, t; cin >> s.first >> s.second >> t.first >> t.second;
  ll N; cin >> N;
  vvi A(N, vi(3));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < 3; j++) {
      cin >> A[i][j];
    }
  }

  vvf D(N + 2, vf(N + 2));
  for (ll i = 0; i < N; i++) {
    for(ll j = 0; j < N; j++) {
      D[i][j] = max<double>(0, dist({A[i][0], A[i][1]}, {A[j][0], A[j][1]}) - (A[i][2] + A[j][2]));
    }
  }

  for (ll i = 0; i < N; i++) {
    D[i][N] = D[N][i] = max<double>(0, dist(s, {A[i][0], A[i][1]}) - A[i][2]);
    D[i][N + 1] = D[N + 1][i] = max<double>(0, dist(t, {A[i][0], A[i][1]}) - A[i][2]);
  }
  D[N][N + 1] = D[N + 1][N] = max<double>(0, dist(s, t));

  vf E(N + 2, (1ll << 60));
  priority_queue<pii, vpii, greater<pii>> pq;
  E[N] = 0;
  pq.push({0, N});
  while (pq.size()) {
    ll fr; tie(ignore, fr) = pq.top();
    pq.pop();
    for (ll to = 0; to < N + 2; to++) {
      if (E[to] > E[fr] + D[fr][to]) {
        E[to] = E[fr] + D[fr][to];
        pq.push({E[to], to});
      }
    }
  }

  cout << fixed << setprecision(10);

  cout << E[N + 1] << endl;
}
