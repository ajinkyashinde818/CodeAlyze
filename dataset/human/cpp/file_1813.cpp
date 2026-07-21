#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;;


  vector<int> e(m);
  for ( int i = 0; i < m; i++ ) {
    cin >> e[i];
    e[i]--;
  }

  bool used[n] = {0};
  for ( int i = m-1; i >= 0; i-- ) {
    if ( !used[e[i]] ) cout << e[i]+1 << endl;
    used[e[i]] = true;
  }
  for ( int i = 0; i < n; i++ ) {
    if ( !used[i] ) cout << i+1 << endl;
  }
  
  return 0;
}
