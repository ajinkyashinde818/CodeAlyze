#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
      int n, k;
      char s[12];

      if(scanf("%d %s %d", &n, s, &k) == 1);

      for(int i = 0; i < n; i++) {
            if(s[i] != s[k - 1]) {
                  s[i] = '*';
            }
            printf("%c", s[i]);
      }

      return 0;
}
