#include <stdio.h>
int main( ){
  int N,i,P,K;
  scanf("%d",&N);

  for(i=0; i < N; i++){
    scanf("%d %d",&P,&K);
    if(P%K == 0){
      printf("%d\n",K);}
    else
      {  printf("%d\n",P%K);}
  }
  return 0;
}
