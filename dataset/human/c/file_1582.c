#include <stdio.h>
#include <string.h>

int abs(int a) {
  return a > 0 ? a : -a;
}

int main(void) {
  int i, j, now = 0, cnt[100010], ans = 0;
  char s[100010], t[100010];
  scanf("%s", s);
  t[0] = cnt[0] = 0;
  for(i = 0; i < strlen(s); ++i) {
    if(s[i] != 'x') t[now] = s[i], t[++now] = 0, cnt[now] = 0;
    else cnt[now]++;
  }
  for(i = 0; i < now; ++i) {
    if(t[i] != t[strlen(t) - i - 1]) {
      printf("-1");
      return 0;
    }
    ans += abs(cnt[i] - cnt[now - i]);
  }
  ans += abs(cnt[now] - cnt[0]);
  printf("%d", ans / 2);
  return 0;
}
