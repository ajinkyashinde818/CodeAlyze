#include <cstdio>
#include <cstring>

using namespace std;

char s[100'009];
int cnt[26];

int main() {
  int n;
  scanf("%d %s", &n, s);
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    ++cnt[(int)(s[i] - 'a')];
  }
  const int mod = 1'000'000'007;
  long long ans = 1;
  for (int i = 0; i < 26; ++i) {
    ans *= cnt[i] + 1;
    ans %= mod;
  }
  ans = (ans - 1 + mod) % mod;
  printf("%d\n", (int)ans);
}
