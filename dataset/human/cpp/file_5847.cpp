#include <bits/stdc++.h>

using namespace std;

struct nod {long long val, p;} v[100002];

long long sum1[100002], m1[100002];
long long sum2[100002], m2[100002];
int n;
long long S, c, sol, nr;

int main()
{
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].p >> v[i].val;
  }
  for (int i = 1; i <= n; i++) {
    S += v[i].val;
    sum1[i] = (S - v[i].p);
    m1[i] = max(m1[i - 1], sum1[i]);
    sol = max(sol, sum1[i]);
  }
  S = 0;
  for (int i = n; i >= 1; i--) {
    S += v[i].val;
    sum2[i] = S - (c - v[i].p);
    m2[i] = max(m2[i + 1], sum2[i]);
    sol = max(sol, sum2[i]);
  }
  for (int i = 1; i <= n; i++) {
    nr = sum1[i] - v[i].p + m2[i + 1];
    sol = max(sol, nr);
  }
  for (int i = n; i >= 1; i--) {
    nr = sum2[i] - (c - v[i].p) + m1[i - 1];
    sol = max(sol, nr);
  }
  cout << sol;
  return 0;
}
