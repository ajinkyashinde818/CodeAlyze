#include<stdio.h>
#define N 200000

main(){
  int i,a,b[N],Max=0,Min=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
  Min = b[0];
  Max = b[1]-b[0];
  for(i=1;i<a;i++){
    if(Max < b[i]-Min){
      Max = b[i]-Min;
    }
    if(Min > b[i]){
      Min = b[i];
    }
  }
  printf("%d\n",Max);
  
  return 0;
}
