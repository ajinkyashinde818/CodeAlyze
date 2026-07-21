#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a (n), b (n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;

  reverse (b.begin(), b.end());
  int l = -1, r = -2;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      if (l == -1) l = r = i;
      else r++;
    }
  }

  if (l == -1) {
    cout << "Yes\n";
    for (auto i : b) cout << i << " ";
    cout << '\n';
    return 0;
  }

  int p = lower_bound (a.begin(), a.end(), a[l]) - a.begin() - 1;
  int q = upper_bound (a.begin(), a.end(), a[l]) - a.begin();
  int lo = 0, hi = n - 1, k = n;
  while (lo <= hi) {
    int mid = (hi - lo) / 2 + lo;
    if (b[mid] < a[l]) {
      k = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  q = max (q, k);
  k = -1;
  lo = 0, hi = n - 1;
  while (lo <= hi) {
    int mid = (hi - lo) / 2 + lo;
    if (b[mid] > a[l]) {
      k = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  p = min (p, k);
  int idx = 0;
  if (p < 0) idx = q;
  for (int i = l; i <= r; i++) {
    if (idx == n) {
      cout << "No\n";
      return 0;
    }
    swap (b[i], b[idx]);
    idx++;
    if (idx == p + 1) idx = q;
  }

  cout << "Yes\n";
  for (auto i : b) cout << i << " ";
  cout << '\n';
}
