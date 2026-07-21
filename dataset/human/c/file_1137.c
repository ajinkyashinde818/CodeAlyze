#include <stdio.h>
#include <string.h>

int main(void) {
  int i, j, n, m;
  char s[120], t[120];
  scanf("%s", s);
  scanf("%s", t);
  n = strlen(s), m = strlen(t);
  for(i = 0; i < n; ++i) for(j = i + 1; j < n; ++j) if(s[i] > s[j]) {
    char tmp;
    tmp = s[i], s[i] = s[j], s[j] = tmp;
  }
  for(i = 0; i < m; ++i) for(j = i + 1; j < m; ++j) if(t[i] < t[j]) {
    char tmp;
    tmp = t[i], t[i] = t[j], t[j] = tmp;
  }
  if(strcmp(s, t) < 0) printf("Yes");
  else printf("No");
  return 0;
}
