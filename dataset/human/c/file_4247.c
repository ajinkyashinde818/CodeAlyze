#include <stdio.h>

int main(void){

  int n,m;
  scanf("%d %d", &n, &m);
  int a[m];
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  long mod = 1000000007;
  long move[n+1];
  for (int i = 0; i < n+1; i++) {
    move[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    move[a[i]] = -1;
  }
  move[0] = 1;
  if (move[1] != -1) {
    move[1] = 1;
  }
  for (int i = 2; i < n+1; i++) {
    if (move[i] == -1) {
      continue;
    }
    if (move[i-1] != -1) {
      move[i] += move[i-1];
      move[i] %= mod;
    }
    if (move[i-2] != -1) {
      move[i] += move[i-2];
      move[i] %= mod;
    }
  }
  long answer = move[n];
  if (answer < 0) {
    answer = 0;
  }
  printf("%ld\n", answer);

  return 0;
}
