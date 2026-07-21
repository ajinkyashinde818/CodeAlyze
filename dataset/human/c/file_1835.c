#include <stdio.h>

int main(void){

  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int b[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  int c[n-1];
  for (int i = 0; i < n-1; i++) {
    scanf("%d", &c[i]);
  }

  int answer = 0;
  for (int i = 0; i < n; i++) {
    answer += b[i];
    if (i != 0 && a[i] == a[i-1]+1) {
      answer += c[a[i-1]-1];
    }
  }

  printf("%d\n", answer);

  return 0;
}
