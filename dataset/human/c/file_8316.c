#include <stdio.h>

int main()
{
  int N;
  int K;
  int i;
  char tmp;

  scanf("%d",&N);
  
  char S[N+1];
  scanf("%s",S);
  S[N]='\0';

  scanf("%d",&K);

  tmp=S[K-1];
  for(i=0;i<N;i++){
    if(S[i]!=tmp){
      S[i]='*';
    }
  }
  
  printf("%s\n",S);
  return 0;
}
