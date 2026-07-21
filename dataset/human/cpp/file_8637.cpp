#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,m;
  string ans="No";
  cin >> n >> m;
  vector<string> a(n),b(m);
  for(long i=0;i<n;i++) cin >> a[i];
  for(long i=0;i<m;i++) cin >> b[i];
  for(long si=0;si<=n-m;si++) {
    for(long sj=0;sj<=n-m;sj++) {
      bool y=true;
      for(long i=0;i<m;i++) for(long j=0;j<m;j++) if(a[si+i][sj+j]!=b[i][j]) y=false;
      if(y) {
        ans="Yes";
      }
    }
  }
  cout << ans << endl;
}
