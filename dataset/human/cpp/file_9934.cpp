#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<int> data(26);
  char a;
  for(int i = 0; i < N; i++){
    cin >> a;
    data.at(a - 'a')++;
  }
  long ans = 1;
  for(int i = 0; i < 26; i++){
    ans *= data.at(i) + 1;
    ans %= 1000000007;
  }
  cout << ans - 1 << endl;
  return 0;
}
