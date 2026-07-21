#include<stdio.h>
int main(){
  int i,n,x,min,dif;
  
  scanf("%d",&n);
  scanf("%d %d",&min ,&i);
  if((dif = i - min) < 0) {
    min = i;
  }
  for(i=2; i<n; i++){
    scanf("%d",&x);
    if(min>x) {
      min=x;
    }
   else if((min<=x) && (x-min > dif)) {
      dif = x - min;
    }
  }
  printf("%d\n",dif);
  return 0;
}
