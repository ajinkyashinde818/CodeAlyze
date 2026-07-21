#include<stdio.h>

int main(void){
  int N,i,work,min,ans=-1000000000;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&work);
    
    if(i==0){
      min=work;
      continue;
    }
 
    if(ans<(work-min)) ans=work-min;

    if(work<min) min=work;
  }

  printf("%d\n",ans);

  return 0;
}
