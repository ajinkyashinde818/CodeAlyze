#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  int k = -1;
  int l = -1;
  for (int i = 2; ; i++) {
    int d = i * (i-1) / 2;
    if (n < d) {
      cout << "No" << endl;
      return 0;
    }
    if (n == d) {
      k = i; l = k-1;
      break;
    }
  }
  cout << "Yes" << endl;
  cout << k << endl;
  vector<int> c; int end_index = 1;
  for (int i = 0; i < k; i++) {
    cout << l; int index = 0; int csize = (int) c.size();
    for (int j = 0; j < l; j++) {
      if (index < csize) {
        cout << " " << c[index];
        c[index]++;
      } else {
        if (index == csize) c.push_back(end_index);
        cout << " " << end_index;
        end_index++;
      }
      index++;
    }
    cout << endl;
  }
  return 0;
}
