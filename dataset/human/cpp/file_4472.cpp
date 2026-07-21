#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  n++;
  vector<int> ans;
  for(int i = 0; i < (n + 1)/2; i++){
    ans.push_back(0);
  }
  for(int i = (n + 1)/2; i < n - 1; i++){
    ans.push_back(m);
  }
  for(int i = 0; i < ans.size(); i++){
    if(i != ans.size() - 1)cout << ans[i] << " ";
    else cout << ans[i] << endl;
  }
  return 0;
}
