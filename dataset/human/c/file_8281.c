#include<stdio.h>
#include<string.h>
int main(void)
{
  int N;
  int K;
  char S[100];
  scanf("%d\n",&N);
  scanf("%s\n",S);
  scanf("%d\n",&K);
  
  for(int i=0;i<N;i++){
	if(S[i]!=S[K-1]){
      S[i]='*';
    }
  }
  printf("%s\n",S);
  return 0;
}
