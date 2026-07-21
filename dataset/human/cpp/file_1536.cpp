#include "bits/stdc++.h"
using namespace std;
const int maxn = 100100;
int main(){
  int n;
  cin >> n;
  int k = 1;
  while(k * (k + 1) / 2 <= n) k++;
  k--;
  if(k * (k + 1) / 2 == n){
    cout << "Yes" << endl;
    cout << k+1 << endl;
    vector<vector<int> > ans;
    vector<int> h0, h1;
    for(int e = 1; e <= k; e++) h0.push_back(e);
    h1.push_back(1);
    for(int e = k+1; e <= k+k-1; e++) h1.push_back(e);
    ans.push_back(h0);
    ans.push_back(h1);
    int top = k+k;
    for(int e = 2; e <= k; e++){
      int col = e - 2 + 1;
      vector<int> hx;
      for(int f = 0; f < e; f++) hx.push_back(ans[f][col]);
      for(int f = e; f < k; f++) hx.push_back(top++);
      ans.push_back(hx);
    }
    for(int e = 0; e < k+1; e++){
      cout << ans[e].size();
      for(int v : ans[e]) cout << " " << v;
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
  return 0;
}
