#include<stdio.h>
#define NUM (1000)
int main()
{
  int G[NUM][NUM];
  int N;
  int i;

  scanf("%d", &N);

  for(i=0; i<N; i++){
    scanf("%d %d", &G[i][0], &G[i][1]);
  }

  for(i=0; i<N; i++){
    if(G[i][0]%G[i][1] == 0){
      printf("%d\n", G[i][1]);
    }
    else
      printf("%d\n", G[i][0]%G[i][1]);
    
  }
  return 0;
}
