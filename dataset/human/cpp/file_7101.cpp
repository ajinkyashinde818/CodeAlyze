#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n;i++) cin >> b[i];
  vector<int> acount(n+1,0);
  vector<int> bcount(n+1,0);
  for (int i=0;i<n;i++) {
    acount[a[i]]++;
    bcount[b[i]]++;
  }
  bool ok = true;
  for (int i=1;i<=n;i++) {
    if (acount[i]+bcount[i] > n) {
      ok = false;
    }
  }
  if(!ok) cout << "No" << endl;
  else {
    vector<int> asum(n+1,0);
    vector<int> bsum(n+1,0);
    for (int i=1;i<=n;i++) {
      asum[i] = asum[i-1]+acount[i];
      bsum[i] = bsum[i-1]+bcount[i];
    }
    int rot = 0;
    for (int i=1;i<=n;i++) {
      rot = max(rot,asum[i]-bsum[i-1]);
    }
    cout << "Yes" << endl;
    for(int i=0;i<n;i++) {
      if (i != 0) cout << ' ';
      cout << b[(i-rot+n)%n];
    }
    cout << endl;
  }
}
