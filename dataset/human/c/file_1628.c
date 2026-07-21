#include <stdio.h>

#define MAX_N 1000
#define MAX_DEPTH MAX_N
#define MAX_LINE_LEN 50
typedef char line_t[MAX_DEPTH + MAX_LINE_LEN + 1];

void convert(int n, line_t line[])
{
  int i, j, p;
  for (i = 0; i < n; i++) {
    for (p = 0; line[i][p] == '.'; p++) { }
    if (p > 0) {
      line[i][p - 1] = '+';
      for (j = i - 1; j >= 0; j--) {
        if (line[j][p - 1] != '.') break;
        line[j][p - 1] = '|';
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (p = 0; line[i][p] != '\0'; p++) {
      if (line[i][p] == '.') line[i][p] = ' ';
    }
  }
}

int main()
{
  static line_t line[MAX_N];
  int n, i;
  for (;;) {
    scanf("%d", &n);
    if (n == 0) break;
    for (i = 0; i < n; i++) {
      scanf("%s", line[i]);
    }
    convert(n, line);
    for (i = 0; i < n; i++) {
      printf("%s\n", line[i]);
    }
  }
  return 0;
}
