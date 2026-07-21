// -----------------------------------
// author   : MatsuTaku
// country  : Japan
// created  : 09/13/20 20:47:40
// -----------------------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int n; cin>>n;
  vector<int> A(n); for (auto& a:A) cin>>a;
  vector<int> B(n); for (auto& b:B) cin>>b;
  auto solve = [&]() {
    reverse(B.begin(), B.end());
    int l = 0, r = n;
    while (l < n and A[l] != B[l])
      l++;
    while (l < r and A[r-1] != B[r-1])
      r--;
    if (l == r) {
      return true;
    }
    int sames = r-l;
    int v = A[l];
    int al = l, ar = r;
    while (0 <= al and (A[al] == v or B[al] == v))
      --al;
    while (ar < n and (A[ar] == v or B[ar] == v))
      ++ar;
    int buf = al+1 + n-ar;
    if (buf < sames)
      return false;
    int i = l;
    while (i < r and 0 <= al) {
      swap(B[al], B[i]);
      ++i;
      --al;
    }
    while (i < r and ar < n) {
      swap(B[i], B[ar]);
      ++i;
      ++ar;
    }
    return true;
  };
  if (solve()) {
    cout << "Yes" << endl;
    for (auto b:B)
      cout << b << " ";
    cout << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
