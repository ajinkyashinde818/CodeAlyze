#include <cstdio>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

using ll = long long;
vector<tuple<ll, ll>> sushis;
ll dp_cw[100000] = {0};
ll dp_ccw[100000] = {0};

int main()
{
  int n;
  ll c;
  scanf("%d %lld", &n, &c);
  for (int i = 0; i < n; i++) {
    ll x;
    ll v;
    scanf("%lld %lld", &x, &v);
    sushis.push_back(make_tuple(x, v));
  }
  ll energy;
  ll max_possible;
  energy = 0;
  max_possible = 0;
  for (int i = 0; i < n; i++) {
    energy += get<1>(sushis[i]);
    max_possible = max(max_possible, energy - get<0>(sushis[i]));
    dp_cw[i] = max_possible;
    // printf("dp_cw[%d] = %d;\n", i, dp_cw[i]);
  }
  energy = 0;
  max_possible = 0;
  for (int i = n-1; 0 <= i; i--) {
    energy += get<1>(sushis[i]);
    max_possible = max(max_possible, energy - (c - get<0>(sushis[i])));
    dp_ccw[i] = max_possible;
    // printf("dp_ccw[%d] = %d;\n", i, dp_ccw[i]);
  }
  ll max_energy = 0;
  for (int i = 0; i < n; i++) {
    max_energy = max(max_energy, dp_cw[i]);
    if (i+1 < n)
      max_energy = max(max_energy, dp_cw[i]-get<0>(sushis[i])+dp_ccw[i+1]);
    max_energy = max(max_energy, dp_ccw[i]);
    if (0 <= i-1)
      max_energy = max(max_energy, dp_ccw[i]-(c-get<0>(sushis[i]))+dp_cw[i-1]);
  }
  printf("%lld\n", max_energy);
  return 0;
}
