#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> Q(m);
  for(int i = 0; i < m; ++i){
    cin >> Q[i];
  }
  reverse(Q.begin(),Q.end());
  vector<int> ans(n,-1);
  vector<bool> used(n+1,false);
  int idx = 0;
  for(auto e : Q){
    if(used[e]) continue;
    ans[idx] = e;
    ++idx;
    used[e] = true;
  }
  for(int i = 1; i <= n; ++i){
    if(used[i]) continue;
    ans[idx] = i;
    ++idx;
  }
  for(auto e : ans)
    cout << e << endl;
}
