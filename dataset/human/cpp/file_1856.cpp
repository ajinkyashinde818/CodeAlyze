#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int e[m];
  bool state[n+1];
  fill(state,state+n+1,false);
  for(int i = 0; i < m; ++i) cin >> e[i];
  for(int i = m-1; i >= 0; --i){
    if(!state[e[i]]){
      cout << e[i] << endl;
      state[e[i]] = true;
    }
  }
  for(int i = 1; i <= n; ++i) if(!state[i]) cout << i << endl;
}
