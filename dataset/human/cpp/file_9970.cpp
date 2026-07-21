#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  vector<int> v(26);
  for (int i = 0; i < n; i++) {
    v[s[i] - 'a']++;
  }

  long long ans = 1;
  for (int i = 0; i < 26; i++) {
    ans = ans * (v[i] + 1) % 1000000007;
  }
  cout << ans - 1 << endl;
}
