#include <bits/stdc++.h>
using namespace std;

int main() {
  const int MOD = 1000000007;
  int n; cin >> n;
  
  vector<int> alphabet(26);
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    alphabet.at(c - 'a')++;
  }
  
  long long answer = 1;
  for (int i = 0; i < 26; i++) {
    answer *= alphabet.at(i) + 1;
    answer %= MOD;
  }
  
  cout << answer - 1 << endl;
}
