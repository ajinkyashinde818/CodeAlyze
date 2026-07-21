#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_int3(char *line, int size, int *a1, int *a2, int *a3) {
  if(!fgets(line, size, stdin)) return;
  sscanf(line, "%d %d %d", a1, a2, a3);
}

#define BUF_SIZE 20

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// assume that a <= b
int gcd(int a, int b) {
  if(a == 0) return b;
  return gcd(b%a, a);
}

int main(void) {
  int a, b, k;
  char line[BUF_SIZE];
  get_int3(line, BUF_SIZE, &a, &b, &k);
  if(a > b) swap(&a, &b);
  int m = gcd(a, b);

  int i;
  int idx = 0;
  int ans = m;
  for(i = m; i >=1; i--) {
    idx += (!(m%i));
    if(k == idx) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
