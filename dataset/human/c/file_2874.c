#include <stdio.h>
int main(void){
  
  int K,S;
  int a,i,j,count=0;
  scanf("%d %d",&K,&S);
  for(i=0;i<=K;i++){
    for(j=0;j<=K;j++){
      a=S-i-j;
        if(0<=a&&a<=K){
         // printf("%d %d %d\n",i,j,a);
          count++;
        }
    }
  }
  printf("%d",count);
}
