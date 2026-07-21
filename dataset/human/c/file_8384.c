#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  char S[N];
  scanf("%s",S);

  int K;
  scanf("%d",&K);

  int chr = S[K-1];

  for(int i = 0;i < N;i++){
    if(S[i] == chr) printf("%c",chr);
    else printf("*");
  }
  printf("\n");

  return 0;
}
