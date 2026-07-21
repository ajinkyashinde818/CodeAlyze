#include <stdio.h>

int main()
{
  int i;
  int N,K;
  int input;
  int count=0;

  scanf("%d %d",&N,&K);

  for(i=0;i<N;i++){
    scanf("%d",&input);
    if(input>=K){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}
