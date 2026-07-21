#include<stdio.h>

int main(){
  int N;
  scanf("%d", &N);

  char s[12];
  scanf("%s", s);

  int K;
  scanf("%d", &K);

  int i;

  int c = s[K - 1];

  for(i = 0; i < N; i++){
    if(s[i] == c) printf("%c", s[i]);
    else printf("*");
  }

  printf("\n");

  return 0;
}
