#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int n;
char s[N], d[N];

int mult(int x, int y) {
  return (1LL * x * y) % mod;
}

int fact(int n) {
  if (n == 0)
    return 1;
  else
    return mult(n, fact(n - 1));
}

void flip(int at) {
  char c = d[at - 1];
  d[at] = (c == 'L' ? 'R' : 'L');
}

int main() {
  scanf("%d %s", &n, s);
  n += n;
  if (s[0] == 'W' || s[n - 1] == 'W') {
    puts("0");
    return 0;
  }
  d[0] = 'L';
  for (int i = 1; i < n; i++) {
    d[i] = d[i - 1];
    if (s[i] == s[i - 1])
      flip(i);
  }
  int l = 1, r = 0, ans = 1;
  for (int i = 1; i < n; i++) {
    if (d[i] == 'R') {
      ans = mult(ans, l - r);
      r++;
    } else {
      l++;
    }
  }
  printf("%d\n", (l != r ? 0 : mult(ans, fact(n / 2))));
  return 0;
}
