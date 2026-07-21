#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    p[i] = n - i - 1;
  }
  for (int i = 0; i < m; i++){
    int e;
    cin >> e;
    e--;
    p[e] = n + i;
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(p[i], i + 1);
  }
  sort(P.rbegin(), P.rend());
  for (int i = 0; i < n; i++){
    cout << P[i].second << endl;
  }
}
