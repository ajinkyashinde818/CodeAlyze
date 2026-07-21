#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN (100000)

int main(int argc, char *argv[]) {
  // read inputs
  char s[MAX_LEN + 1];
  scanf("%s", s);
  const int n = strlen(s);

  // remove all 'x's in s
  char s_nox[MAX_LEN + 2];
  int m = 0, indices[MAX_LEN + 2], is_palindrome = 1;
  s_nox[0] = '_';
  indices[0] = -1;
  for (int i = 0; i < n; i++) {
    const char c = s[i];
    if (c != 'x') {
      m++;
      s_nox[m] = c;
      indices[m] = i;
    }
  }
  s_nox[m + 1] = '_';
  indices[m + 1] = n;
  // check whether s_nox is a palindrome (if its not print -1)
  for (int i = 0; i < (m + 2) / 2; i++) {
    if (s_nox[i] != s_nox[m + 1 - i]) {
      is_palindrome = 0;
      break;
    }
  }
  if (!is_palindrome) {
    printf("-1\n");
    exit(0);
  }

  // When 2 adjacent non-'x' characters have 'x's between them,
  // the corresponding range on the other side must have the same
  // number of 'x's in them.
  int ans = 0;
  for (int i = 1; i < (m + 3) / 2; i++) {
    const int num_x_left = indices[i] - indices[i - 1] - 1;
    const int num_x_right = indices[m + 1 - (i - 1)] - indices[m + 1 - i] - 1;
    ans += abs(num_x_left - num_x_right);
  }
  printf("%d\n", ans);

  return 0;
}
