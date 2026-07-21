/*input
5
abcab
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
  int r = a + b;
  if (r >= MOD) r -= MOD;
  return r;
}

int mul(int a, int b) {
  return int((long long)a * b % MOD);
}

int sub(int a, int b) {
  int r = MOD + a - b;
  if (r >= MOD) r -= MOD;
  return r;
}

int cnt[32];

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n;
  scanf("%d\n", &n);

  char s[100005];
  scanf("%s", s);

  for (int i = 0; i < n; ++i)
  {
    cnt[s[i]-'a']++;
  }

  int ans = 1;
  for (int i = 0; i < 26; ++i)
  {
    ans = mul(ans, cnt[i] + 1);
  }

  printf("%d\n", sub(ans, 1));

  return 0;
}
