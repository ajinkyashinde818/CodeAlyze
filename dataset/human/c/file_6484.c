#include<stdio.h>
#define M 200000

int main(){

  int i,n,min,max;
  int I[M];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&I[i]);
  }

  min=I[0];
  max=I[1]-I[0];

  for(i=1;i<n;++i){
    max=(max<(I[i]-min))?(I[i]-min) : max;
    min=(min>I[i])?I[i] : min;
  }

  printf("%d\n",max);

  return 0;
}
