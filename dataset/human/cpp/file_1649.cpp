#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
int k;
int id[100010];
int num[100010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> n;
  bool can = false;
  for (k = 1; k*(k-1) <= 2 * n; k++) {
    if (k*(k-1) == 2 * n) {
      can = true;
      break;
    }
  }
  if (n == 2 || !can) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  if (n == 1) {
    cout << 2 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  cout << k << endl;
  int sz = 2 * n / k;
  cout << sz;
  for (int i = 1; i <= n; i++) {
    id[i] = -i;
  }
  for (int j = 0; j < sz; j++) {
    cout << " " << j+1;
    id[j+1] = 1;
    num[j+1] = 1;
  }
  cout << endl;
  int st = 1;
  for (int i = 0; i < k-1; i++) {
    cout << sz;
    int tmp = 0, p = st;
    vector<int> v;
    // cout << i << " " << p << endl;
    for (int j = 0; j < sz; j++) {
      while (p <= n && (id[p] == tmp || num[p] == 2)) p++;
    //   cout << " " << j << " " << tmp << " " << p << " " << id[p] << endl;
      cout << " " << p;
      tmp = id[p];
      num[p]++;
      v.emplace_back(p);
    }
    cout << endl;
    if (num[st] == 2) st++;
    for (int j = 0; j < v.size(); j++) {
      id[v[j]] = i+2;
    }
  }

  return 0;
}
