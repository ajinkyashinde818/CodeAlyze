#include<iostream>

using namespace std;

int main(void) {
  long mod = 1000000007;
  int n;
  cin >> n;
  char str[n + 1];
  cin >> str;
  int cnt[26] = {};
  for (int i = 0; i < n; i++) {
    cnt[0 + str[i] - 'a']++;
  }
  long long int res = 1;
  for (int i = 0; i < 26; i++) {
    res *= (cnt[i] + 1);
    res %= mod;
  }
  res -= 1;
  cout << res << endl;
  return 0;
}
