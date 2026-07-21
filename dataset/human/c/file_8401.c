#include <stdio.h>

int main(void){

  int n,k;
  scanf("%d", &n);
  char s[n+1];
  scanf("%s %d", s, &k);
  for (int i = 0; i < n; i++) {
    if (s[i] != s[k-1]) {
      s[i] = '*';
    }
  }
  printf("%s\n", s);

  return 0;
}
