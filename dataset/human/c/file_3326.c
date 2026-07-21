#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN_S (100000)

int possible(const char *s) {
  // printf("[possible] s = %s\n", s);
  if (s[0] == '\0')
    return 1;
  else
    return (strstr(s, "dream") == s && possible(s + 5)) ||
        (strstr(s, "dreamer") == s && possible(s + 7)) ||
        (strstr(s, "erase") == s && possible(s + 5)) ||
        (strstr(s, "eraser") == s && possible(s + 6));
}

int main(int argc, char *argv[]) {
  int len;
  char S[MAXLEN_S + 1];
  fgets(S, MAXLEN_S + 1, stdin);
  len = strlen(S);
  S[len - 1] = '\0';
  if (possible(S))
    printf("YES\n");
  else
    printf("NO\n");
}
