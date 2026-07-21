#include<stdio.h>
#include<stdlib.h>

#define MAX(A, B) (((A) > (B)) : (A) ? (B))

int main() {
  int a, b, c;
  int d;
  scanf("%d %d %d", &a, &b, &c);
  
  if (a + b > c - 2) {
    d = b + c;
  }
  else {
    d = a + b + b + 1;
  }
  printf("%d\n", d);
  return 0;
}
