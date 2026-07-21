#include <stdio.h>
#include <string.h>

void sort(char *s);

int main(void) {
  char s[101], t[101], N, M;
  int i, j;
  scanf("%s %s", s, t);

  N = strlen(s);
  M = strlen(t);

  for (j = 0; j < N && j < M; j++) {
    int xchg, tmp;

    for (xchg = j, i = j + 1; i < N; i++) {
      if (s[i] < s[xchg]) xchg = i;
    }
    tmp = s[j];
    s[j] = s[xchg];
    s[xchg] = tmp;

    for (xchg = j, i = j + 1; i < M; i++) {
      if (t[i] > t[xchg]) xchg = i;
    }
    tmp = t[j];
    t[j] = t[xchg];
    t[xchg] = tmp;

    if (s[j] < t[j]) {
      printf("Yes\n");
      return 0;
    } else if (s[j] > t[j]) {
      printf("No\n");
      return 0;
    }
  }

  if (N < M) printf("Yes\n");
  else printf("No\n");

  return 0;
}
