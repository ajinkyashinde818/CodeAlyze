#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int i,j,n,min,max,get,*rate;
  //?????????
  scanf("%d",&n);
  rate=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    scanf("%d",&rate[i]);
  min=rate[n-1];
  max=rate[n-1];
  get=-2000000000;//????°?????????±

  //??????:??????????????????
  for(i=n-2;0<=i;i--){
    if(min>rate[i+1])
      min=rate[i+1];
    if(max<rate[i+1])
      max=rate[i+1];
    if(get<max-rate[i])
      get=max-rate[i];
  }
  printf("%d\n",get);
  
  //??????
  free(rate);
  return(0);
}
