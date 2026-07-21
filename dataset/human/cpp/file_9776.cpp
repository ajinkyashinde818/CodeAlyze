#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int n, a[30], mod = 1000000007;
string s;

void mul(int &a, int b) {
  a = (1ll * a * b) % mod; 
}

int main() {
  cin >> n >> s;
  sort(s.begin(), s.end());
  for(int i = 0; i < n; ++i)
    ++a[s[i] - 'a'];
  int cnt = 1;
  for(int i = 0; i <= ('z' - 'a'); ++i)
    mul(cnt, a[i] + 1);
  cout << (cnt - 1) << endl;
}
