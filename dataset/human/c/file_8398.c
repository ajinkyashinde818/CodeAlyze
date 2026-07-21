#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n, k, sc;
  char hit, s[32];
  sc = scanf("%d", &n);
  sc = scanf("%s", s);
  sc = scanf("%d", &k);
  hit = s[k - 1];
  for(int i = 0; i < n; i++) {
    if(s[i] != hit) {
      s[i] = '*';
    }
  }
  printf("%s", s);
  return 0;
}
