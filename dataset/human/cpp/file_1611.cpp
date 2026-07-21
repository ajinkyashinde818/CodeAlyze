#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int tmp = n;
  int cnt = 1;
  while (1) {
    tmp -= cnt;
    if (tmp == 0) {
      break;
    }
    if (tmp > 0) {
      cnt++;
    }
    if (tmp < 0) {
      puts("No");
      return 0;
    }
  }
  cout << "Yes" << endl;
  cout << cnt + 1 << endl;
  tmp = n;
  vector<vector<int>> a(cnt + 1);
  while (tmp) {
    for (int i = 0; i < cnt; i++) {
      a[cnt].push_back(tmp);
      a[cnt - i - 1].push_back(tmp);
      tmp--;
    }
    cnt--;
  }
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].size() << " ";
    for (int j = 0; j < a[i].size(); j++) {
      cout << a[i][j];
      if (j != a[i].size() - 1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
