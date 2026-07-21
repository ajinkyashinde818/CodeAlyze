#include <stdio.h>
#define N 200005


int main(void){
  int n,r[N],i,d,min;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&r[i]);
  }
  min=r[0];
  d=-r[0];
  for(i=1;i<n;i++){
    if(r[i]-min>d){
      d=r[i]-min;
    }
    if(r[i]<min){
      min=r[i];
    }
  }
  
  printf("%d\n",d);
  
  return 0;
}
