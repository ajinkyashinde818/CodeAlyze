#include<stdio.h>
int main(void){
  int N,D[100][2],count=0,max=0;
  
  scanf("%d",&N);
  
  for(int i=0; i<N; i++){
    scanf("%d %d", &D[N][0], &D[N][1]);
    if(D[N][0] == D[N][1]){
      count++;
      if(count>max)
        max=count;
    }
    else
      count=0;
  }
  
  if(max>=3)
    printf("Yes");
  else
    printf("No");
  
  return 0;
}
