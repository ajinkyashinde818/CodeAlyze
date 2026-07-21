// ------------------
// author: MatsuTaku
// date  : 22/02/2020
// ------------------

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int N, R; cin>>N>>R;
  if (N >= 10) {
    cout << R << endl;
  } else {
    cout << (R+100*(10-N)) << endl;
  }

  return 0;
}
