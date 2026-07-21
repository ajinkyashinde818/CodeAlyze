#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int k = 0;
  for (int i = 1; i < N + 2; i++) {
    if (i * (i - 1) / 2 == N) {
      k = i;
    }
  }
  if (!k) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  cout << k << endl;

  vector<vector<int>> mat(k + 1, vector<int>(k + 1, 0));
  int c = 1;
  for (int i = 1; i < k + 1; i++) {
    for (int j = 1; j < i; j++) {
      mat[i][j] = c++;
    }
  }
  
  for (int i = 1; i < k + 1; i++) {
    set<int> s;
    for (int j = 1; j < k + 1; j++) {
      if(mat[i][j]) s.insert(mat[i][j]);
      if(mat[j][i]) s.insert(mat[j][i]);
    }

    vector<int> v(begin(s), end(s));
    cout << v.size() << ' ';
    for (int j = 0; j < (int)v.size(); j++) {
      cout << v[j] << ( (j == (int)v.size() - 1) ? '\n' : ' ' );
    }
  }

  return 0;
}
