#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, i, j, k;
  string s, ans="No";
  cin >> n >> m;
  
  vector<string> a, b;
  
  for (k=0; k<n; k++) {
    cin >> s;
    a.push_back(s);
  }
  for (k=0; k<m; k++) {
    cin >> s;
    b.push_back(s);
  }
  
  for (i=0; i<=n-m; i++) {
    for (j=0; j<=n-m; j++) {
      for (k=0; k<m; k++) {
        s = a[i+k].substr(j, m);
        if (b[k] != s) break;
        if (k == (m-1)) ans ="Yes"; 
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;  
}
