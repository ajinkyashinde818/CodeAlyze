#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  string s;
  bool found = false;
  cin >> n >> m;
  vector<string> ns, ms;
  for (int i=0; i<n; i++) {
    cin >> s;
    ns.push_back(s);
  }
  for (int i=0; i<m; i++) {
    cin >> s;
    ms.push_back(s);
  }
  for (int i=0; i<=n-m; i++) {
    for (int j=0; j<=n-m; j++) {
      found = true;
      for (int k=0; k<m; k++) {
        if (ns[i+k].substr(j,m)!=ms[k]) {
          found = false;
          break;
        }
      }
      if (found) break;
    }
    if (found) break;
  }
  if (found) cout << "Yes";
  else cout << "No";
  return 0;
}
