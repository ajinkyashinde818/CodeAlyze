#include <stdio.h>
#include <math.h>

int main(void) {

  long n;
  scanf("%ld", &n);
  char s[n+1];
  scanf("%s", s);
  long mod = pow(10,9)+7;
  long alp[26];
  for (int i = 0; i < 26; i++) {
    alp[i] = 0;
  }
  for (long i = 0; i < n; i++) {
    alp[s[i]-'a']++;
  }
  long answer = 1;
  for (int i = 0; i < 26; i++) {
    answer *= alp[i]+1;
    answer %= mod;
  }
  answer--;
  printf("%ld\n", answer);

  return 0;
}
