#include<stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  char s[n+10];
  scanf("%s", s);

  int K[26] = {};

  int i;
  int k;
  for(i = 0; i < n; i++){
    k = s[i] - 97;
    K[k]++;
  }

  long long answer = 1;

  for(i = 0; i < 26; i++){
    answer *= K[i] + 1;
    answer %= 1000000000 + 7;
  }

  printf("%lld\n", answer - 1);

  return 0;
}
