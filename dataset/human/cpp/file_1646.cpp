#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int s = 1;
  int nn = n;
  while (nn > s) {
    nn -= s;
    s += 1;
  }
  if (nn < s) {
    cout << "No" << endl;
    return 0;
  }
  s += 1;
  vector<vector<int>> v(s);
  for (int i = 0; i < s; ++i){
    v[i].reserve(s);
  }
  int cnt = 1;
  for (int i = 0; i < s; ++i) {
    for (int j = i+1; j < s; ++j) {
      v[i].push_back(cnt);
      v[j].push_back(cnt);
      cnt += 1;
    }
  }

  cout << "Yes" << endl;
  cout << s << endl;
  for(int i = 0; i < s; ++i) {
    cout << s-1;
    for(int j = 0; j < s-1; ++j) {
      cout << " " << v[i][j];
    }
    cout << endl;
  }
}
