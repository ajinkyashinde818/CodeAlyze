#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  int s = 1000000010, t;
  for (int i = 0; i < n; i++){
    cin >> a.at(i);
    if (abs(a.at(i)) < s){
      s = abs(a.at(i));
      t = i;
    }
  }
  int mins = 0;
  for (int i = 0; i < n; i++){
    if (a.at(i) < 0) mins++;
  }
  mins %= 2;

  int64_t ans = 0;
  for (int i = 0; i < n; i++){
    if (mins == 1 && i == t) ans += (-1) * abs(a.at(i));
    else ans += abs(a.at(i));
  }
  cout << ans << endl;
  return 0;
}
