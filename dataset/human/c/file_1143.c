#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
}
int compareReverse(const void *a, const void *b) {
  return *(char *)b - *(char *)a;
}
int main() {
  char s[101], t[101];
  unsigned slen, tlen, i, lmin;
  scanf("%s", s);
  scanf("%s", t);
  slen = strlen(s);
  tlen = strlen(t);
  lmin = slen > tlen ? tlen : slen;
  qsort(s, slen, sizeof(char), compare);
  qsort(t, tlen, sizeof(char), compareReverse);
  for (i = 0; i < lmin; i++) {
    if (s[i] < t[i]) {
      puts("Yes");
      return 0;
    } else if (s[i] > t[i]) {
      puts("No");
      return 0;
    }
  }
  puts(slen < tlen ? "Yes" : "No");
  return 0;
}
