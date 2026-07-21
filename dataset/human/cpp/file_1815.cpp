#include <iostream>
#include <vector>

using namespace std;

signed main()
{
  int n, m; cin >> n >> m;
  int e[m]; vector<bool> u(n+1, false);
  for(int i = 0; i < m; i++) cin >> e[i];
  for(int i = m-1; i >= 0; i--) {
    if(!u[e[i]]) cout << e[i] << endl, u[e[i]] = true;
  }
  for(int i = 1; i <= n; i++) {
    if(!u[i]) cout << i << endl;
  }

  return 0;
}
