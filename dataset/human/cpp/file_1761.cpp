#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> vec(n);
  for(int i = 0; i < n; ++i){
    vec[i].first = n - i - 1;
    vec[i].second = i + 1;
  }
  int e;
  for(int i = n; i < n + m; ++i){
    cin >> e;
    vec[e - 1].first = i;
  }
  sort(vec.begin(), vec.end(), greater<pair<int, int>>());
  for(int i = 0; i < n; ++i){
    cout << vec[i].second << endl;
  }
  return 0;
}
