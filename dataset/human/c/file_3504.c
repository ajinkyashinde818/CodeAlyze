#include <stdio.h>

int main(void){

  long n,k;
  scanf("%ld %ld", &n, &k);
  long a[n+1];
  for (long i = 1; i <= n; i++) {
    scanf("%ld", &a[i]);
  }
  int visited[n+1][2];
  visited[1][0] = 1;
  visited[1][1] = 0;
  for (long i = 2; i <= n; i++) {
    visited[i][0] = 0;
  }
  long cur = 1;
  long telepote = 0;
  long f_a,f_b;
  while (1) {
    telepote++;
    cur = a[cur];
    if (telepote == k) {
      printf("%ld\n", cur);
      return 0;
    }
    if (visited[cur][0] == 0) {
      visited[cur][0] = 1;
      visited[cur][1] = telepote;
    } else {
      if (cur == 1) {
        f_a = 0;
        f_b = telepote;
      } else {
        f_a = visited[cur][1];
        f_b = telepote-visited[cur][1];
      }
      break;
    }
  }
  long left = k-telepote;
  left %= f_b;
  telepote = 0;
  while (1) {
    if (telepote == left) {
      printf("%ld\n", cur);
      break;
    }
    telepote++;
    cur = a[cur];
  }

  return 0;
}
