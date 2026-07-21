#include <stdio.h>
#include <string.h>

int main(void)
{
  char c[256] = {['a'] = 2, ['b'] = 3, ['c'] = 5};
  char s[3 + 1];
  int ans = 1;

  if (scanf("%3s%*[^\n]%*c", s) > 0) {
    for (int i = 0; i < strlen(s); i++) {
      ans *= c[s[i]];
    }
    puts(ans == c['a'] * c['b'] * c['c'] ? "Yes" : "No");
  }
}
