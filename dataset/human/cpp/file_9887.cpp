#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> x(26, 0);
  for (int i = 0; i < s.length(); i++) {
    x[s[i] - 'a']++;
  }
  long long ans = 1;
  for (int i = 0; i < 26; i++) {
    ans *= (x[i] + 1);
    ans %= 1000000007;
  }
  
  cout << ans - 1;
  return 0;
}
