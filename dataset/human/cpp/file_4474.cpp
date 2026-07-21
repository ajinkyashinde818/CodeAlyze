#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<int> ans;
  for(int i=0; i < n/2+1; i++){
    ans.push_back(0);
  }
  for(int i=n/2+1; i < n; i++){
    ans.push_back(m);
  }
  for(int i=0; i < n-1; i++){
    cout << ans[i] << " ";
  }
  cout << ans[n-1] << endl;
  return 0;
}
