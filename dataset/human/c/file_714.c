#include <stdio.h>
#include <stdlib.h>

#define MAX_N (100000L)
#define SIZE_BUF (30L)
#define NUM_MOD (1000000007L)

int main(int argc, char *argv[]) {
  // read inputs
  long N;
  char cs[MAX_N + 1], buf[SIZE_BUF];
  scanf("%ld", &N);
  fgets(buf, SIZE_BUF, stdin);
  scanf("%s", cs);
  // printf("%s\n", cs);

  // count number of each letter
  long cnts[26] = {};
  for (long i = 0; i < N; i++) {
    cnts[cs[i] - 'a']++;
  }

  // solve
  long ans = 1;
  for (long i = 0; i < 26; i++) {
    ans = ans * (cnts[i] + 1) % NUM_MOD;
  }
  printf("%ld\n", ans - 1);

  return 0;
}
