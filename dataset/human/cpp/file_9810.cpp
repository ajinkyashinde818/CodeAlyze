#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> c(26);
  for (int i = 0; i < n; i++) {
    c.at(s.at(i) - 'a')++;
  }
  long product = 1;
  for (int i = 0; i < 26; i++) {
    product *= c.at(i) + 1;
    product %= 1000000007;
  }
  cout << product - 1 << endl;
}
